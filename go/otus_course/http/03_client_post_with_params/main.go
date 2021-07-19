package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

func main() {

	type AddRequest struct {
		Id    int    `json:"id"`
		Title string `json:"title"`
		Text  string `json:"text"`
	}

	addReq := &AddRequest{
		Id:    123,
		Title: "for loop",
		Text:  "text",
	}

	jsonBody, _ := json.Marshal(&addReq)
	fmt.Println(jsonBody)

	request, err := http.NewRequest(http.MethodPost, "https://ya.ru", bytes.NewBuffer(jsonBody))
	if err != nil {
		log.Fatal(err)
	}

	//Check how does request look like
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
	fmt.Printf("%T", bodyStr)
}
