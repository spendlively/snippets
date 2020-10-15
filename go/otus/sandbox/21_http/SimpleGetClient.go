package main

import (
	"fmt"
	"log"
	"net/http"
	"net/url"
)

func SimpleGetClient() {

	// создаем HTTP клиент
	client := &http.Client{}

	//1.
	//reqUrl, _ := url.Parse("https://yandex.ru/search/?text=golang&lr=65")

	//2.
	reqUrl, _ := url.Parse("https://yandex.ru")
	reqUrl.Path = "/search/"
	reqArgs := url.Values{}
	reqArgs.Add("text", "golang")
	reqArgs.Add("lr", "65")
	reqUrl.RawQuery = reqArgs.Encode()

	// создаем GET-запрос
	req, _ := http.NewRequest("GET", reqUrl.String(), nil)
	// выполняем запрос
	req.Header.Add("User-Agent", `Mozilla/5.0 Gecko/20100101 Firefox/39.0`)
	resp, err := client.Do(req)
	//fmt.Println(resp)

	//Обработка ответа
	// выполняем запрос
	if err != nil {
		// или другая уместная обработка
		log.Fatal(err)
	}
	// если ошибки не было - нам необходимо "закрыть" тело ответа
	// иначе при повторном запросе будет открыто новое сетевое соединение
	defer resp.Body.Close()

	// проверяем HTTP status ответа
	if resp.StatusCode != 200 {
		// обработка HTTP статусов зависит от приложения
		fmt.Errorf("unexpected http status: %s", resp.Status)
	}

	// возможно проверяем какие-то заголовки
	ct := resp.Header.Get("Content-Type")
	fmt.Println(ct)
	//if ct != "application/json" {
	//	log.Fatalf("unexpected content-type: %s", ct)
	//}

	// считываем тело ответа (он может быть большим)
	//body, _ := ioutil.ReadAll(resp.Body)
	fmt.Println(resp.Body)
}
