package main

import (
	"fmt"
	"time"
)

type Mutex struct {
	ch chan struct{}
}

func NewMutex() Mutex {

	mu := Mutex{
		ch: make(chan struct{}),
	}

	mu.Unlock()

	return mu
}

func (mu *Mutex) Lock() {
	<-mu.ch
}

func (mu *Mutex) Unlock() {
	go func() {
		mu.ch <- struct{}{}
	}()
}

func main() {

	var counter int
	mu := NewMutex()

	go func() {
		mu.Lock()
		counter = 1
		mu.Unlock()
	}()

	go func() {
		mu.Lock()
		counter = 2
		mu.Unlock()
	}()

	<-time.After(time.Millisecond)

	mu.Lock()
	fmt.Println(counter)
	mu.Unlock()
}
