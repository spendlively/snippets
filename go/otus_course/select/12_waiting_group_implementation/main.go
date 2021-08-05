package main

import (
	"fmt"
	"sync"
)

type WaitGroup struct {
	counter int
	done    chan struct{}
	mu      sync.Mutex
}

func NewWaitGroup() WaitGroup {
	return WaitGroup{
		done: make(chan struct{}),
	}
}

func (wg *WaitGroup) Add(count int) {
	wg.mu.Lock()
	wg.counter += count
	wg.mu.Unlock()
}

func (wg *WaitGroup) Done() {
	wg.mu.Lock()
	wg.counter--
	if wg.counter == 0 {
		close(wg.done)
	}
	wg.mu.Unlock()
}

func (wg *WaitGroup) Wait() {
	<-wg.done
}

func main() {

	var counter int
	wg := NewWaitGroup()

	wg.Add(1)
	go func() {
		defer wg.Done()
		counter = 1
	}()

	wg.Wait()
	fmt.Println(counter)
}
