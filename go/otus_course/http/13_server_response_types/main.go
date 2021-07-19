package main

import (
	"encoding/json"
	"log"
	"net/http"
)

//Available routes:
//http://localhost:8080/json
//http://localhost:8080/text-html

// Все нужные объекты: конфиг, логер, соединение с базой и т.п.
type MyHandler struct{}

// Реализуем интерфейс `http.Handler`
func (h *MyHandler) json(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.WriteHeader(http.StatusOK)
	json.NewEncoder(w).Encode(map[string]string{"type": "json"})
}

// Реализуем интерфейс `http.Handler`
func (h *MyHandler) textHtml(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "text/html; charset=utf-8")
	w.WriteHeader(http.StatusOK)
	w.Write([]byte("Text html"))
}

func main() {
	handler := &MyHandler{}
	mux := http.NewServeMux()
	mux.HandleFunc("/json", handler.json)
	mux.HandleFunc("/text-html", handler.textHtml)
	server := &http.Server{
		Addr:
		":8080",
		Handler: mux,
	}
	log.Fatal(server.ListenAndServe())
}
