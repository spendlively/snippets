package main

import (
	"context"
	"encoding/json"
	"log"
	"net/http"
)

//Available routes:
//http://localhost:8080/user

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

type MyUser struct {
	name string
}

// Реализуем интерфейс `http.Handler`
func (h *MyHandler) AddItem(w http.ResponseWriter, r *http.Request) {
	ctx := r.Context()
	user := ctx.Value("currentUser").(*MyUser)
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	w.WriteHeader(http.StatusOK)
	json.NewEncoder(w).Encode(map[string]string{"user": user.name})
}

func authorize(h http.HandlerFunc) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		user, err := DoAuthorizeUser(r)
		if err != nil {
			w.WriteHeader(http.StatusForbidden)
			return
		}
		ctx := context.WithValue(r.Context(), "currentUser", user)
		r = r.WithContext(ctx)
		h(w, r)
	}
}

func DoAuthorizeUser(r *http.Request) (*MyUser, error) {
	return &MyUser{
		name: "Ivan",
	}, nil
}

func main() {
	handler := &MyHandler{}
	mux := http.NewServeMux()
	mux.HandleFunc("/user", authorize(handler.AddItem))
	server := &http.Server{
		Addr:
		":8080",
		Handler: mux,
	}
	log.Fatal(server.ListenAndServe())
}
