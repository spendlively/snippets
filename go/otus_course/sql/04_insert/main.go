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

	ctx := context.Background()
	query := `insert into books(id, title, description, created_at, updated_at) values($1, $2, $3, $4, $5)`
	result, err := db.ExecContext(ctx, query,
		4, "Букварь", "Описание", "2019-12-31", "2019-12-31",
	)

	// sql.Result
	if err != nil {
		log.Fatalln(err)
	}

	// Авто-генерируемый ID (SERIAL)
	eventId, err := result.LastInsertId()
	if err != nil {
		log.Fatalln(err)
	} else {
		fmt.Println(eventId)
	}

	// int64
	// Количество измененных строк
	rowsAffected, err := result.RowsAffected() // int64
	if err != nil {
		log.Fatalln(err)
	} else {
		fmt.Println(rowsAffected)
	}
}
