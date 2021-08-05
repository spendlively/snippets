package main

import (
	"fmt"
	"sync"
)

func task() {

	data := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}

	input1 := make(chan int)
	input2 := make(chan int)
	input3 := make(chan int)
	output := make(chan int)

	go func() {
		defer func() {
			close(input1)
			close(input2)
			close(input3)
		}()

		for _, value := range data {
			select {
			case input1 <- value:
			case input2 <- value:
			case input3 <- value:
			}
		}
	}()

	var wg sync.WaitGroup

	wg.Add(1)
	go func() {
		defer wg.Done()
		for value := range input1 {
			output <- value * value
		}
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		for value := range input2 {
			output <- value * value
		}
	}()

	wg.Add(1)
	go func() {
		defer wg.Done()
		for value := range input3 {
			output <- value * value
		}
	}()

	go func() {
		wg.Wait()
		close(output)
	}()

	for value := range output {
		fmt.Println(value)
	}
}

func main() {
	task()
}
