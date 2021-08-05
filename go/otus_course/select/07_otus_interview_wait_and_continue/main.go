package main

import (
	"context"
	"fmt"
	"os"
	"os/signal"
	"sync"
	"syscall"
	"time"
)

const (
	WgCaseTitle      = "wg"
	TimeoutCaseTitle = "timeout"
	SignalCaseTitle  = "signal"
)

func Task(sleep, timeout time.Duration, signals chan os.Signal) string {
	var wg sync.WaitGroup
	var message string

	wg.Add(1)
	go func() {
		defer wg.Done()
		time.Sleep(sleep)
	}()

	// Поменяйте код ниже так, чтобы при достижении определёного таймаута (например, 100 ms)
	// мы не блокировались на Wait(), а функция продолжала свою работу.
	ctx, cancel := context.WithCancel(context.Background())
	go func() {
		wg.Wait()
		cancel()
	}()

	select {
	case <-ctx.Done():
		message = WgCaseTitle
	case <-time.After(timeout):
		message = TimeoutCaseTitle
	case <-signals:
		message = SignalCaseTitle
	}

	return message
}

func main() {
	sleep := 2 * time.Second
	timeout := 1 * time.Second

	signals := make(chan os.Signal, 1)
	signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)

	fmt.Println(Task(sleep, timeout, signals))

	signal.Stop(signals)
	close(signals)
}
