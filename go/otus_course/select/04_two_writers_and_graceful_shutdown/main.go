package main

import (
	"context"
	"fmt"
	"os"
	"os/signal"
	"sync"
	"syscall"
	"time"
)

func TwoWritersWithGracefulShutdown(signals chan os.Signal) {

	ch := make(chan int)
	defer close(ch)

	ctx, cancel := context.WithCancel(context.Background())

	var wg sync.WaitGroup

	// Listening the signals for graceful shutdown.
	wg.Add(1)
	go func() {
		defer wg.Done()
		<-signals
		cancel()
	}()

	// Writer 1.
	wg.Add(1)
	go func() {
		defer wg.Done()
		for {
			select {
			case <-ctx.Done():
				fmt.Println("Writer 1 is done.")
				return
			case ch <- 1:
				time.Sleep(time.Second)
			}
		}
	}()

	// Writer 2.
	wg.Add(1)
	go func() {
		defer wg.Done()
		for {
			select {
			case <-ctx.Done():
				fmt.Println("Writer 2 is done.")
				return
			case ch <- 2:
				time.Sleep(time.Second)
			}
		}
	}()

	// Reader.
	wg.Add(1)
	go func() {
		defer wg.Done()
		for {
			select {
			case <-ctx.Done():
				fmt.Println("Reader is done.")
				return
			case value, opened := <-ch:
				fmt.Println(value)
				if !opened {
					return
				}
			}
		}
	}()

	wg.Wait()

	fmt.Println("Bye-bye!")
}

func main() {

	signals := make(chan os.Signal, 1)
	signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)

	go func() {
		TwoWritersWithGracefulShutdown(signals)
	}()

	time.Sleep(3 * time.Second)

	fmt.Println("Sending an interrupt signal...")
	signals <- os.Interrupt

	time.Sleep(1 * time.Second)

	signal.Stop(signals)
	close(signals)
}
