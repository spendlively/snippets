package main

import (
	"go.uber.org/zap"
	"go.uber.org/zap/zapcore"
	"time"
)

func main() {
	config := zap.NewDevelopmentConfig()
	config.EncoderConfig.EncodeTime = syslogTimeEncoder
	config.EncoderConfig.EncodeLevel = customLevelEncoder

	//config.EncoderConfig.

	logger, _ := config.Build()

	logger.Info("Syslog style timestamp")
	//Jul 17 14:50:35 [info]  04_custom_prodaction_config_example/main.go:15 Syslog style timestamp
}

func syslogTimeEncoder(t time.Time, enc zapcore.PrimitiveArrayEncoder) {
	enc.AppendString(t.Format("Jan 2 15:04:05"))
}

func customLevelEncoder(level zapcore.Level, enc zapcore.PrimitiveArrayEncoder) {
	enc.AppendString("[" + level.String() + "]")
}
