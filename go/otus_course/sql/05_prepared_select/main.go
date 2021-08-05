package main

import (
	"database/sql"
	"fmt"
	_ "github.com/jackc/pgx/stdlib"
	"log"
)

func main() {
	dsn := "postgres://anthony:anthony@localhost:5432/books?sslmode=disable"

	// *sql.DB
	db, err := sql.Open("pgx", dsn)
	if err != nil {
		log.Fatalf("failed to load driver: %v", err)
	}

	stmt, err := db.Prepare("select id, title, description from books where title = $1") // *sql.Stmt
	if err != nil {
		log.Fatal(err)
	}

	// освобождаем ресурсы в СУБД
	defer stmt.Close()

	// многократно выполняем запрос
	names := []string{"Мастер и Маргарита", "Граф Монте-Кристо", "Марсианин", "Букварь"}
	for _, name := range names {
		row := stmt.QueryRow(name)

		var id int64
		var title, descr string

		if err := row.Scan(&id, &title, &descr); err != nil {
			// ошибка сканирования
			log.Fatalln(err)
		}

		// обрабатываем строку
		fmt.Printf("%d %s %s\n", id, title, descr)
	}
}
