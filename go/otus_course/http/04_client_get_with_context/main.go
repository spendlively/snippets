package main

import (
	"context"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"time"
)

func main() {
	request, err := http.NewRequest(http.MethodGet, "https://ya.ru", nil)
	if err != nil {
		log.Fatal(err)
	}

	ctx, cancel := context.WithTimeout(context.Background(), 3*time.Second)
	defer cancel()

	request = request.WithContext(ctx)
	response, err := http.DefaultClient.Do(request)
	if err != nil {
		log.Fatal(err)
	}

	//Когда делаем запрос, запускается горутина,
	//кот выполняет соединение и обрабатывает данные.
	//Поэтому response.Body нужно закрывать (response.Body.Close())
	//чтобы дать горутине сигнал для закрытия.
	defer response.Body.Close() // <-- Зачем?

	body, err := ioutil.ReadAll(response.Body)
	if err != nil {
		log.Fatal(err)
	}

	//Body (string)
	bodyStr := string(body)
	fmt.Printf("%v", bodyStr)
}
