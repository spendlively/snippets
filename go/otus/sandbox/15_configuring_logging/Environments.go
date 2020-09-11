package main

import (
	"fmt"
	"log"
	"os"
	"strconv"
)

type EnvConfig struct {
	Port int
	Host string
}

func Environments() {
	httpPort, err := strconv.Atoi(os.Getenv("SHORTENER_PORT"))
	if err != nil {
		panic(fmt.Sprint("SHORTENER_PORT not defined"))
	}

	shortenerHost := os.Getenv("SHORTENER_HOST")
	if shortenerHost == "" {
		panic(fmt.Sprint("SHORTENER_HOST not defined"))
	}

	config := EnvConfig{httpPort, shortenerHost}
	log.Println(config.Port)
	log.Println(config.Host)
}
