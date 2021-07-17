package main

import (
	"go.uber.org/zap"
	"time"
)

func main() {
	logger := zap.NewExample()
	defer logger.Sync() //flushes buffer

	url := "site.ru"
	sugar := logger.Sugar()

	sugar.Info(
		"Unable to fetch url",
		zap.String("url", url),
		zap.Int("attempt", 3),
		zap.Duration("backoff", time.Second),

	)
}
