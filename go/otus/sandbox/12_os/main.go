package main

import (
	"io/ioutil"
	"log"
	"os"
)

func main() {
	content := []byte("temporary file's content")
	// файл будет создан в os.TempDir, например /tmp/example-Jsm22jkn
	tmpfile, err := ioutil.TempFile("", "example-")
	if err != nil {
		log.Fatal(err)
	}
	defer os.Remove(tmpfile.Name()) // не забываем удалить
	if _, err := tmpfile.Write(content); err != nil {
		log.Fatal(err)
	}
	if err := tmpfile.Close(); err != nil {
		log.Fatal(err)
	}
}
