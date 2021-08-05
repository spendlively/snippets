package main

import (
	"database/sql"
	"fmt"
	"log"

	_ "github.com/jackc/pgx/stdlib"
)

func main() {
	dsn := "postgres://anthony:anthony@localhost:5432/books?sslmode=false"

	// *sql.DB
	db, err := sql.Open("pgx", dsn)
	if err != nil {
		log.Fatalf("failed to load driver: %v", err)
	}

	fmt.Println(db)
}
