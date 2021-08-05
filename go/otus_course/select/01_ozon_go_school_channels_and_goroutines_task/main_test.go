package main

import (
	"github.com/stretchr/testify/require"
	"testing"
)

func TestMerge2Channels(t *testing.T) {
	t.Run("06_send_lock_close_panic", func(t *testing.T) {
		ch1 := make(chan int)
		ch2 := make(chan int)
		out := make(chan int)
		n := 10

		go func() {
			for i := 0; i < n; i++ {
				ch1 <- i
			}
		}()

		go func() {
			for i := 0; i < n; i++ {
				ch2 <- i
			}
		}()

		Merge2Channels(square, ch1, ch2, out, n)

		result := <-out
		expectedResult := 570
		require.Equal(t, result, expectedResult, "Expected: %q, given %q", expectedResult, result)
	})
}
