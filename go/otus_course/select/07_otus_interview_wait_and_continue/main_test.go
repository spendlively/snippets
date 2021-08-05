package main

import (
	"os"
	"os/signal"
	"syscall"
	"testing"
	"time"

	"github.com/stretchr/testify/require"
)

func TestTask(t *testing.T) {
	t.Run("test wg", func(t *testing.T) {
		sleep := 50 * time.Millisecond
		timeout := 100 * time.Millisecond

		signals := make(chan os.Signal, 1)
		signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)

		result := Task(sleep, timeout, signals)

		signal.Stop(signals)
		close(signals)

		require.Equal(t, result, WgCaseTitle, "Expected %s, got %s", WgCaseTitle, result)
	})

	t.Run("test timeout", func(t *testing.T) {
		sleep := 100 * time.Millisecond
		timeout := 50 * time.Millisecond

		signals := make(chan os.Signal, 1)
		signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)

		result := Task(sleep, timeout, signals)

		signal.Stop(signals)
		close(signals)

		require.Equal(t, result, TimeoutCaseTitle, "Expected %s, got %s", TimeoutCaseTitle, result)
	})

	t.Run("test signal", func(t *testing.T) {
		sleep := 200 * time.Millisecond
		timeout := 300 * time.Millisecond

		signals := make(chan os.Signal, 1)
		signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)

		go func() {
			time.Sleep(100 * time.Millisecond)
			signals <- os.Interrupt
		}()

		result := Task(sleep, timeout, signals)

		signal.Stop(signals)
		close(signals)

		require.Equal(t, result, SignalCaseTitle, "Expected %s, got %s", SignalCaseTitle, result)
	})
}
