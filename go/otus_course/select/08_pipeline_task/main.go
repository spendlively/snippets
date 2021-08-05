package main

import (
	"context"
	"fmt"
	"os"
	"os/signal"
	"syscall"
	"time"
)

func pipeline(signals chan os.Signal) bool {

	ch1 := make(chan int)
	ch2 := make(chan int)
	ctx, cancel := context.WithCancel(context.Background())

	go func() {
		<-signals
		cancel()
	}()

	go func() {
		defer close(ch1)
		i := 0
		for {
			select {
			case <-ctx.Done():
				return
			case ch1 <- i:
				i++
				time.Sleep(time.Second)
			}
		}
	}()

	go func() {
		defer close(ch2)
		for {
			select {
			case <-ctx.Done():
				return
			case i, ok := <-ch1:
				if ok {
					i = i * i
					ch2 <- i
				}
			}
		}
	}()

	for i := range ch2 {
		fmt.Println(i)
	}

	fmt.Println("Bye-bye")

	return true
}

func main() {

	signals := make(chan os.Signal, 1)
	signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)

	pipeline(signals)

	signal.Stop(signals)
	close(signals)
}
