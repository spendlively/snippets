package main

import (
	"context"
	"database/sql"
	"fmt"
	"log"

	_ "github.com/jackc/pgx/stdlib"
)

func main() {
	dsn := "postgres://anthony:anthony@localhost:5432/books?sslmode=disable"

	// *sql.DB
	db, err := sql.Open("pgx", dsn)
	if err != nil {
		log.Fatalf("failed to load driver: %v", err)
	}

	query := `select id, title, description from books where id = $1`
	ctx := context.Background()
	rows, err := db.QueryContext(ctx, query, 4)
	if err != nil {

		// ошибка при выполнении запроса
		log.Fatalln(err)
	}
	defer rows.Close()

	for rows.Next() {
		var id int64
		var title, descr string
		if err := rows.Scan(&id, &title, &descr); err != nil {
			// ошибка сканирования
			log.Fatalln(err)
		}

		// обрабатываем строку
		fmt.Printf("%d %s %s\n", id, title, descr)
	}

	if err := rows.Err(); err != nil {
		// ошибка при получении результатов
		log.Fatalln(err)
	}
}
