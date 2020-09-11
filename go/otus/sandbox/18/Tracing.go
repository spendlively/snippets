package main

import (
	"os"
	"runtime/trace"
)

func Tracing() {
	file, _ := os.Create("tracing_file.txt")
	trace.Start(file)
	defer trace.Stop()

	ch := make(chan int)

	go func() {
		ch <- 42
	}()

	<-ch
}
