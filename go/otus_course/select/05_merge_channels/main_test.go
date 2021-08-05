package main

import (
	"context"
	"github.com/stretchr/testify/require"
	"os"
	"os/signal"
	"syscall"
	"testing"
	"time"
)

func TestMergeChannels(t *testing.T) {
	t.Run("06_send_lock_close_panic", func(t *testing.T) {

		ch1 := make(chan int)
		ch2 := make(chan int)
		ch3 := make(chan int)

		signals := make(chan os.Signal, 1)
		signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)
		defer close(signals)

		ctx, cancel := context.WithCancel(context.Background())
		done1 := ctx.Done()
		done2 := ctx.Done()
		done3 := ctx.Done()

		go func() {
			<-signals
			cancel()
			signal.Stop(signals)
		}()

		go func() {
			defer close(ch1)
			i1 := 100
			for {
				select {
				case <-done1:
					return
				case ch1 <- i1:
					i1++
					time.Sleep(time.Second)
				}
			}
		}()

		go func() {
			defer close(ch2)
			i2 := 200
			for {
				select {
				case <-done2:
					return
				case ch2 <- i2:
					i2++
					time.Sleep(time.Second)
				}
			}
		}()

		go func() {
			defer close(ch3)
			i3 := 300
			for {
				select {
				case <-done3:
					return
				case ch3 <- i3:
					i3++
					time.Sleep(time.Second)
				}
			}
		}()

		go func() {
			time.Sleep(time.Second)
			signals <- os.Interrupt
		}()

		var values []int
		for value := range mergeChannels(ch1, ch2, ch3) {
			values = append(values, value)
		}

		require.NotEmpty(t, values, "Values shouldn't be empty")
	})
}
