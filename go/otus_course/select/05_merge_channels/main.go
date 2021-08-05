package main

import (	"context";	"fmt"
	"os"
	"os/signal"
	"syscall"
	"time"
)

func mergeChannels(ch1, ch2, ch3 chan int) <-chan int {
	out := make(chan int)

	var ch1Closed, ch2Closed, ch3Closed bool

	go func() {
		defer close(out)
		for {
			select {
			case v, ok := <-ch1:
				if ok {
					out <- v
				} else {
					ch1Closed = true
				}
			case v, ok := <-ch2:
				if ok {
					out <- v
				} else {
					ch2Closed = true
				}
			case v, ok := <-ch3:
				if ok {
					out <- v
				} else {
					ch3Closed = true
				}
			}

			if ch1Closed && ch2Closed && ch3Closed {
				fmt.Println("Closing out...")
				return
			}
		}
	}()

	return out
}

func main() {

	ch1 := make(chan int)
	ch2 := make(chan int)
	ch3 := make(chan int)

	signals := make(chan os.Signal, 1)
	signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)
	defer close(signals)

	ctx, cancel := context.WithCancel(context.Background())

	go func() {
		<-signals
		cancel()
		signal.Stop(signals)
	}()

	go func() {
		defer close(ch1)
		i := 100
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
		i := 200
		for {
			select {
			case <-ctx.Done():
				return
			case ch2 <- i:
				i++
				time.Sleep(time.Second)
			}
		}
	}()

	go func() {
		defer close(ch3)
		i := 300
		for {
			select {
			case <-ctx.Done():
				return
			case ch3 <- i:
				i++
				time.Sleep(time.Second)
			}
		}
	}()

	for out := range mergeChannels(ch1, ch2, ch3) {
		fmt.Println(out)
	}

	fmt.Println("Bye bye!")
}
