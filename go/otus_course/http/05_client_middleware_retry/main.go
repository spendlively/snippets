package main

import (
	"context"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"time"
)

//MiddleWare
// - замыкание

//Применение MiddleWare для клиента
// - Замерить
// - Залогировать
// - Повторить запросы (retry)

type Retry struct {
	http.RoundTripper
}

//Native retry every 2 seconds
func (r *Retry) RoundTrip(req *http.Request) (*http.Response, error) {
	for {
		resp, err := r.RoundTripper.RoundTrip(req)

		if err == nil && resp.StatusCode < 500 {
			return resp, err
		}

		select {
		case <-req.Context().Done():
			log.Println("Cancel by timeout")
			return resp, req.Context().Err()
		case <-time.After(200 * time.Millisecond):
			log.Println("retry")
		}
	}
}

func main() {

	client := &http.Client{
		Transport: &Retry{http.DefaultTransport},
	}

	//request, err := http.NewRequest(http.MethodGet, "https://ya.ru", nil)
	request, err := http.NewRequest(http.MethodGet, "https://wrong-url.ru", nil)
	if err != nil {
		log.Fatalf("Cound not create request")
	}

	//ctx := context.Background()
	ctx, cancel := context.WithTimeout(context.Background(), 10*time.Second)
	defer cancel()

	request = request.WithContext(ctx)

	response, err := client.Do(request)
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
