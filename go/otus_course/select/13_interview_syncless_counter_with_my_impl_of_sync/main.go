package main

import "fmt"

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

type WaitGroup struct {
	counter int
	done    chan struct{}
	mu      Mutex
}

func NewWaitGroup() WaitGroup {
	return WaitGroup{
		mu:   NewMutex(),
		done: make(chan struct{}),
	}
}

func (wg *WaitGroup) Add(count int) {
	wg.mu.Lock()
	wg.counter += count
	wg.mu.UnLock()
}

func (wg *WaitGroup) Done() {
	wg.mu.Lock()
	wg.counter--
	if wg.counter == 0 {
		close(wg.done)
	}
	wg.mu.UnLock()
}

func (wg *WaitGroup) Wait() {
	<-wg.done
}

func main() {

	var counter int
	mu := NewMutex()
	wg := NewWaitGroup()

	for i := 0; i < 1000; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			mu.Lock()
			counter++
			mu.UnLock()
		}()
	}

	wg.Wait()
	fmt.Println(counter)
}
