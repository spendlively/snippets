package main

import (
	"github.com/stretchr/testify/require"
	"os"
	"os/signal"
	"syscall"
	"testing"
	"time"
)

func TestPipeline(t *testing.T) {

	t.Run("test", func(t *testing.T) {

		signals := make(chan os.Signal, 1)
		signal.Notify(signals, syscall.SIGINT, syscall.SIGHUP)

		go func() {
			<-time.After(time.Second)
			signals <- os.Interrupt
		}()

		result := pipeline(signals)

		signal.Stop(signals)
		close(signals)

		require.Equal(t, result, true, "expected %v, got %v", true, result)
	})
}
