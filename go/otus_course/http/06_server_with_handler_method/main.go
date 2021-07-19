package main

import (
	"encoding/json"
	"net/http"
	"time"
)

//Available routes:
//http://localhost:8080/search

// Все нужные объекты: конфиг, логер, соединение с базой и т.п.
type MyHandler struct {

}

// Реализуем интерфейс `http.Handler`
// Эта функция будет обрабатывать входящие запросы
func (h *MyHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {

	if r.URL.Path == "/search" {
		//args := r.URL.Query()
		//
		//query := args.Get("query")
		//fmt.Println(query)
		//
		//limit, err := strconv.Atoi(args.Get("limit"))
		//fmt.Println(limit)
		//if err != nil {
		//	w.WriteHeader(http.StatusBadRequest)
		//	return
		//}

		results := map[string]bool{"success": true}
		if len(results) == 0 {
			w.WriteHeader(http.StatusInternalServerError)
			return
		}

		w.Header().Set("Content-Type", "application/json; charset=utf-8")
		w.WriteHeader(http.StatusOK)
		json.NewEncoder(w).Encode(results)
	}
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
