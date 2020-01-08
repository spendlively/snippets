package main

import (
	"fmt"
	"os"
	"time"
)

//Даже без использования горутин
//при запуске всегда создается минимум 5 потоков
func main() {
	fmt.Printf("Main goroutine start (Pid = %v)\n", os.Getpid())
	time.Sleep(100 * time.Second)
	fmt.Println("Main goroutine end")
}
