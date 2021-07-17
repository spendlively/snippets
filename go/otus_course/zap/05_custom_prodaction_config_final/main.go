package main

import (
	"go.uber.org/zap"
	"go.uber.org/zap/zapcore"
	"gopkg.in/natefinch/lumberjack.v2"
	"time"
)

func TimeEncoder(t time.Time, enc zapcore.PrimitiveArrayEncoder) {
	enc.AppendString(t.Format("2006-01-02 15:04:05"))
}

func main() {

	file := "/tmp/prod.log"
	level := zap.InfoLevel
	size := 500
	backups := 3
	age := 30

	encoderConfig := zap.NewProductionEncoderConfig()
	encoderConfig.EncodeTime = TimeEncoder
	core := zapcore.NewCore(
		zapcore.NewConsoleEncoder(encoderConfig),
		zapcore.AddSync(&lumberjack.Logger{
			Filename:   file,
			MaxSize:    size,
			MaxBackups: backups,
			MaxAge:     age,
		}),
		level,
	)
	logger := zap.New(core)

	logger.Error("DefaultLogger init success")
	//2021-07-17 15:15:28	error	DefaultLogger init success
}
