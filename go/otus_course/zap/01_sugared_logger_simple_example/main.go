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

	sugar.Infow(
		"Unable to fetch url",
		"url", url,
		"attempt", 3,
		"backoff", time.Second,

	)

	//sugar.Infof("Unable to fetch url: %s", url)
	//
	//sugar.Infof("Unable to fetch url")
}
