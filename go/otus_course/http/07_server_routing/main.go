package main

import (
	"encoding/json"
	"net/http"
	"time"
)

//Available routes:
//http://localhost:8080/search
//http://localhost:8080/add

// Все нужные объекты: конфиг, логер, соединение с базой и т.п.
type MyHandler struct{}

// Реализуем интерфейс `http.Handler`
// Эта функция будет обрабатывать входящие запросы
func (h *MyHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	switch r.URL.Path {
	case "/search":
		h.Search(w, r)
	case "/add":
		h.AddItem(w, r)
	default:
		http.NotFound(w, r)
	}
}

// Реализуем интерфейс `http.Handler`
func (h *MyHandler) Search(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.WriteHeader(http.StatusOK)
	json.NewEncoder(w).Encode(map[string]string{"route": "Search"})
}

// Реализуем интерфейс `http.Handler`
func (h *MyHandler) AddItem(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.WriteHeader(http.StatusOK)
	json.NewEncoder(w).Encode(map[string]string{"route": "AddItem"})
}

func main() {
	handler := &MyHandler{}
	server := &http.Server{
		Addr:         ":8080",
		Handler:      handler,
		ReadTimeout:  10 * time.Second,
		WriteTimeout: 10 * time.Second,
	}
	server.ListenAndServe()
}
