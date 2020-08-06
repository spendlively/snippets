package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func signalHandler(c <-chan os.Signal) {
	s := <-c
	// TODO: handle
	fmt.Println("Got signal:", s)
}

func businessLogic() {
	fmt.Println(fmt.Sprintf("[%d]", os.Getpid()), "App is ready to receive signals")
	for {}
}

func Signals() {
	c := make(chan os.Signal, 1)
	signal.Notify(c, syscall.SIGUSR1)
	signal.Ignore(syscall.SIGINT)
	go signalHandler(c)
	businessLogic()
}
