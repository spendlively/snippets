package main

import (
	"fmt"
	"time"
)

func main() {

	ch := make(chan int)
	n := 10

	// Writer (closes the channel)
	go func() {
		for i := 0; i < n; i++ {
			ch <- i + 1
		}
		close(ch)
	}()

	// Reader 1
	go func() {
	L:
		for {
			select {
			case value, ok := <-ch:
				fmt.Printf("For select: %v %v\n", value, ok)
				if !ok {
					// Brake from both "select" and "for"
					break L
				}
				time.Sleep(time.Nanosecond)
			}
		}
	}()

	// Reader 2
	// For ... range breaks when the channel is closed
	for value := range ch {
		fmt.Printf("For range: %v\n", value)
		time.Sleep(time.Nanosecond)
	}
}
