package main

import "fmt"

func main() {

	ch := make(chan int)
	n := 10

	for i := 1; i <= n; i++ {
		go func(ch chan int, num int) {
			ch <- num
		}(ch, i)
	}

	for i := 1; i < n; i++ {
		fmt.Println(<-ch)
	}

}
