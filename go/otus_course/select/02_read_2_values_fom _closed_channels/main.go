package main

import "fmt"

func main() {

	chBuf := make(chan int, 2)
	ch := make(chan int)

	go func() {
		chBuf <- 21
		chBuf <- 22
		ch <- 11

		close(chBuf)
		close(ch)
	}()

	chBuf1, okBuf1 := <-chBuf
	chBuf2, okBuf2 := <-chBuf
	ch1, ok1 := <-ch

	// now channels are closed,
	// so we can read from closed channels
	// without locking

	chBuf3, okBuf3 := <-chBuf
	ch2, ok2 := <-ch

	fmt.Println(chBuf1, okBuf1)
	fmt.Println(chBuf2, okBuf2)
	fmt.Println(chBuf3, okBuf3)

	fmt.Println(ch1, ok1)
	fmt.Println(ch2, ok2)
}
