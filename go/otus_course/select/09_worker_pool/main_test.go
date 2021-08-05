package main

import (
	"github.com/stretchr/testify/require"
	"testing"
)

func TestTask(t *testing.T) {
	t.Run("test", func(t *testing.T) {
		require.NotPanics(t, task, "Func task should not panic")
	})
}
