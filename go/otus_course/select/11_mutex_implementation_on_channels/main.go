package main

import (
	"fmt"
	"time"
)

type Mutex struct {
	ch chan struct{}
}

func NewMutex() Mutex {
	ch := make(chan struct{}, 1)
	ch <- struct{}{}
	return Mutex{ch}
}

func (m *Mutex) Lock() {
	<-m.ch
}

func (m *Mutex) UnLock() {
	m.ch <- struct{}{}
}

func main() {

	var value int
	mu := NewMutex()

	go func() {
		mu.Lock()
		value = 1
		mu.UnLock()
	}()

	go func() {
		mu.Lock()
		value = 2
		mu.UnLock()
	}()

	time.Sleep(100 * time.Millisecond)

	mu.Lock()
	fmt.Println(value)
	mu.UnLock()
}
