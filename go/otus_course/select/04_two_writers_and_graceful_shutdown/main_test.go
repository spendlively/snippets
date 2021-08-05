package main

import (
	"github.com/stretchr/testify/require"
	"os"
	"os/signal"
	"syscall"
	"testing"
	"time"
)

// Start this code by: go 06_send_lock_close_panic -v -count=10 -race .
func TestTwoWritersWithGracefulShutdown(t *testing.T) {
	t.Run("06_send_lock_close_panic", func(t *testing.T) {

		signals := make(chan os.Signal, 1)
		signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)

		go func() {
			TwoWritersWithGracefulShutdown(signals)
		}()

		//time.Sleep(time.Millisecond)
		time.Sleep(3 * time.Second)

		signals <- os.Interrupt

		signal.Stop(signals)

		require.Equal(t, 1, 1, "Expected: %q, given %q", 1, 1)
	})
}
