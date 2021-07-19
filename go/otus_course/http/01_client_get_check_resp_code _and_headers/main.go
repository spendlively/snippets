package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func main() {
	response, err := http.Get("https://ya.ru/")
	if err != nil {
		log.Fatal(err)
	}

	//Когда делаем запрос, запускается горутина,
	//кот выполняет соединение и обрабатывает данные.
	//Поэтому response.Body нужно закрывать (response.Body.Close())
	//чтобы дать горутине сигнал для закрытия.
	defer response.Body.Close() // <-- Зачем?

	// Http status
	fmt.Println(response.StatusCode)

	//Header
	fmt.Println(response.Header.Get("Content-Type"))

	//Body []uint8
	body, err := ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}

	//Body (string)
	bodyStr := string(body)
	fmt.Println(bodyStr)

}
