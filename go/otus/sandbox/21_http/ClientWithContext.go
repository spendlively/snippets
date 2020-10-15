package main

import (
	"context"
	"fmt"
	"net/http"
	"net/url"
)

func ClientWithContext() {

	// создаем HTTP клиент
	client := &http.Client{}

	reqUrl, _ := url.Parse("https://yandex.ru/search/?text=golang&lr=65")
	req, _ := http.NewRequest("GET", reqUrl.String(), nil)
	req.Header.Add("User-Agent", `Mozilla/5.0 Gecko/20100101 Firefox/39.0`)

	ctx := context.Background()
	//ctx, cancel := context.WithTimeout(ctx, 3*time.Second)
	ctx, cancel := context.WithTimeout(ctx, 3)
	defer cancel()
	//Важно присвоить новый request и вызывать его
	req = req.WithContext(ctx)

	resp, _ := client.Do(req)

	//nil
	fmt.Println(resp)
}
