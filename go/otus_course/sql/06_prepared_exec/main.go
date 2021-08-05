package main

import (
	"database/sql"
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

	stmt, err := db.Prepare("delete from books where title = $1") // *sql.Stmt
	if err != nil {
		log.Fatal(err)
	}

	// освобождаем ресурсы в СУБД
	defer stmt.Close()

	// многократно выполняем запрос
	names := []string{"Букварь"}
	for _, name := range names {
		_, err := stmt.Exec(name)
		if err != nil {
			log.Fatal(err)
		}
	}
}
