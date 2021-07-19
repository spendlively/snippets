package main

import (
	"context"
	"encoding/json"
	"log"
	"net/http"
	"time"
)

//MiddleWare
// - замыкание

//Применение MiddleWare для сервера
// - проверка аутентификации
// - проверка доступа
// - логирование
// - сжатие ответа
// - трассировка запросов в микросервисах

// Все нужные объекты: конфиг, логер, соединение с базой и т.п.
type MyHandler struct{}

// Реализуем интерфейс `http.Handler`
func (h *MyHandler) Search(writer http.ResponseWriter, request *http.Request) {
	//ctx := request.Context()
	//results, err := DoBusinessLogicRequest(ctx, query, limit)
	writer.Header().Set("Content-Type", "application/json; charset=utf-8")
	writer.WriteHeader(http.StatusOK)
	json.NewEncoder(writer).Encode(map[string]string{"route": "Search"})
}

func withTimeout(handler http.HandlerFunc, timeout time.Duration) http.HandlerFunc {
	return func(writer http.ResponseWriter, request *http.Request) {
		ctx, cancel := context.WithTimeout(request.Context(), timeout)
		defer cancel()

		request = request.WithContext(ctx)
		handler(writer, request)
	}
}

func main() {
	handler := &MyHandler{}
	mux := http.NewServeMux()
	mux.HandleFunc("/search", withTimeout(handler.Search, 5*time.Second))
	server := &http.Server{
		Addr:    ":8080",
		Handler: mux,
	}
	log.Fatal(server.ListenAndServe())
}
