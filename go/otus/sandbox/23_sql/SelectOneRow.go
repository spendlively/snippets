package main

import (
	"context"
	"database/sql"
	"fmt"
	_ "github.com/jackc/pgx/stdlib"
	"log"
	"time"
)

func SelectOneRow() {
	////////////////////////////////
	/////////////Connect////////////
	////////////////////////////////
	dsn := "postgres://photo_moderation_local:spend860819@localhost:5432/photo_moderation_local"
	//dsn := "user=myuser dbname=mydb sslmode=verify-full password=mypass"
	db, err := sql.Open("pgx", dsn) // *sql.DB
	if err != nil {
		log.Fatalf("failed to load driver: %v", err)
	}

	////////////////////////////////
	/////////////Select/////////////
	////////////////////////////////
	ctx, _ := context.WithTimeout(context.Background(), 2000*time.Millisecond)
	query := "select id, text from app_alert where id = $1"
	row := db.QueryRowContext(ctx, query, 1)

	var id int64
	var text string

	err = row.Scan(&id, &text)
	//row закроется сама, не надо закрывать
	if err == sql.ErrNoRows {
		fmt.Println("Not found")
	} else if err != nil {
		fmt.Println("Error", err)
	} else {
		fmt.Println("id: ", id, ", text: ", text)
	}
}
