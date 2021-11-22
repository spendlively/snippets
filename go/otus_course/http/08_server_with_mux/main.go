package main

import (
	"encoding/json"
	"log"
	"net/http"
)

//Available routes:
//http://localhost:8080/search
//http://localhost:8080/add

// Все нужные объекты: конфиг, логер, соединение с базой и т.п.
type MyHandler struct{}

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
	mux := http.NewServeMux()
	mux.HandleFunc("/search", handler.Search)
	mux.HandleFunc("/add", handler.AddItem)
	server := &http.Server{
		Addr:    ":8080",
		Handler: mux,
	}
	log.Fatal(server.ListenAndServe())
}
