package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"net/url"
)

func main() {

	//https://yandex.ru/search/?text=42&lr=65

	requestArgs := url.Values{}
	requestArgs.Add("text", "42")
	requestArgs.Add("lr", "65")

	requestUrl, err := url.Parse("https://yandex.ru/search")
	if err != nil {
		log.Fatal(err)
	}

	requestUrl.RawQuery = requestArgs.Encode()

	request, err := http.NewRequest(http.MethodGet, requestUrl.String(), nil)
	if err != nil {
		log.Fatal(err)
	}

	request.Header.Add("User-Agent", `Mozilla/5.0 Gecko/20100101 Firefox/39.0`)

	//*http.Request
	fmt.Printf("%+v\n", request)

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
	fmt.Println(bodyStr)
}
