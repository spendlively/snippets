package main

import (
	"context"
	"database/sql"
	_ "github.com/jackc/pgx/stdlib"
	"log"
	"time"
)

func main() {
	dsn := "postgres://anthony:anthony@localhost:5432/books?sslmode=disable"

	// *sql.DB
	db, err := sql.Open("pgx", dsn)
	if err != nil {
		log.Fatalf("failed to load driver: %v", err)
	}

	// Create a new context
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	//Begin a transaction
	tx, err := db.BeginTx(ctx, nil)
	if err != nil {
		log.Fatal(err)
	}
	// `tx` is an instance of `*sql.Tx` through which we can execute our queries

	// Here, the query is executed on the transaction instance, and not applied to the database yet
	_, err = tx.ExecContext(ctx, "DELETE from books WHERE id = $1", 10)
	if err != nil {
		// Incase we find any error in the query execution, rollback the transaction
		tx.Rollback()
		return
	}

	// The next query is handled similarly
	_, err = tx.ExecContext(ctx, "DELETE from books WHERE id = $1", 20)
	if err != nil {
		tx.Rollback()
		return
	}

	// Finally, if no errors are recieved from the queries, commit the transaction
	// this applies the above changes to our database
	err = tx.Commit()
	if err != nil {
		log.Fatal(err)
	}

	// далее объект tx не пригоден для использования
}
