package main

import (
	"gopkg.in/yaml.v2"
	"io/ioutil"
	"log"
)

type Config struct {
	Domain    string   `yaml:"domain"`
	Blacklist []string `yaml:"blacklist"`
}

func Configuring() {
	var c Config

	yamlFile, err := ioutil.ReadFile("conf.yaml")
	if err != nil {
		log.Fatal(err)
	}

	err = yaml.Unmarshal(yamlFile, &c)
	if err != nil {
		log.Fatalf("Unmarshal: %v", err)
	}

	log.Println(c.Domain)
	log.Println(c.Blacklist)
}
