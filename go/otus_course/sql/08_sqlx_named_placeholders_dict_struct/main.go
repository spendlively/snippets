package main

import (
	"context"
	"fmt"
	"github.com/jmoiron/sqlx"
	"log"

	_ "github.com/jackc/pgx/stdlib"
)

type Book struct {
	Id        int
	Title     string
	Descr     string `db:"description"`
	Meta      string
	CreatedAt string `db:"created_at"`
	UpdatedAt string `db:"updated_at"`
}

func main() {
	dsn := "postgres://anthony:anthony@localhost:5432/books?sslmode=disable"

	// *sql.DB
	db, err := sqlx.Open("pgx", dsn)
	if err != nil {
		log.Fatalf("failed to load driver: %v", err)
	}

	////////////////////////
	//////Select by map/////
	////////////////////////
	sql := "select * from books where id = :id and title = :title"
	rows, err := db.NamedQueryContext(context.Background(), sql, map[string]interface{}{
		"id":    1,
		"title": "Мастер и Маргарита",
	})
	if err != nil {
		log.Fatalln(err)
	}

	for rows.Next() {
		results := make(map[string]interface{})
		err := rows.MapScan(results)
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println(results["title"])
	}

	/////////////////////////
	//////Select by Dict/////
	/////////////////////////
	sql = "select * from books where id = :id and title = :title"
	rows, err = db.NamedQueryContext(context.Background(), sql, Book{
		Id:    1,
		Title: "Мастер и Маргарита",
	})
	if err != nil {
		log.Fatalln(err)
	}

	var books = make([]Book, 5)
	for rows.Next() {
		var book Book

		err := rows.StructScan(&book)
		if err != nil {
			log.Fatal(err)
		}

		books = append(books, book)

		fmt.Println(book.Title)
	}
}
