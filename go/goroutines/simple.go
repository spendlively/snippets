package main

import (
	"fmt"
	"os"
	"time"
)

func foo(name int, ch chan int) {
	fmt.Printf("%v goroutine start\n", name)
	time.Sleep(100 * time.Second)
	fmt.Printf("%v goroutine end\n", name)
	ch <- name
}

func main() {
	ch := make(chan int)
	fmt.Printf("Main goroutine start (Pid = %v) (GOMAXPROCS=%s)\n", os.Getpid(), os.Getenv("GOMAXPROCS"))
	for i := 1; i <= 100; i++ {
		go foo(i, ch)
	}
	//go foo(1, ch)
	fmt.Println("Main goroutine end")
	<-ch
}

//GOMAXPROCS=4 go run simple.go
