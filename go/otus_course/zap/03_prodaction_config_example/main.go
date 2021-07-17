package main

import (
	"go.uber.org/zap"
)

func main() {
	config := zap.NewDevelopmentConfig()

	logger, _ := config.Build()

	logger.Info("Syslog style timestamp")
	//2021-07-17T14:52:44.480+0700    INFO    03_prodaction_config_example/main.go:12  Syslog style timestamp
}
