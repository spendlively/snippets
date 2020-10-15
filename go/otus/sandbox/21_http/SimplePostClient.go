package main

type AddRequest struct {
	Id    int    `json:"id"`
	Title string `json:"title"`
	Text  string `json:"text"`
}

func SimplePostClient() {
	//// создаем HTTP клиент
	//client := &http.Client{}
	//
	//// Запрос в виде Go структуры
	//addReq := &AddRequest{
	//	Id:    123,
	//	Title: "for loop",
	//	Text:  "...",
	//}
	//
	//// Создаем буфер (io.Reader) из которого клиент возьмет тело запроса
	//var body bytes.Buffer
	//json.NewEncoder(body).Encode(addReq)
	//
	//// создаем POST-запрос
	//req, _ := http.NewRequest("POST", "https://site.ru/add_item", body)
	//
	//// выполняем запрос
	//resp, err := client.Do(req)
	////fmt.Println(resp)
}
