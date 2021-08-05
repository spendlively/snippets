package main

import (
	"fmt"
)

func main() {

	var counter int
	ch := make(chan struct{})

	for i := 0; i < 1000; i++ {
		go func() {
			counter++
			ch <- struct{}{}
		}()
		<-ch
	}

	fmt.Println(counter)
}
