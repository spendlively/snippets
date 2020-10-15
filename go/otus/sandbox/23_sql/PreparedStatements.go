package main

import (
	"database/sql"
	"fmt"
	_ "github.com/jackc/pgx/stdlib"
	"log"
)

func PreparedStatements() {
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
	/////////////Prepare/////////////
	////////////////////////////////
	// создаем подготовленный запрос
	stmt, err := db.Prepare("delete from app_alert where id = $1") // *sql.Stmt
	//db.PrepareContext(...) // *sql.Stmt
	if err != nil {
		fmt.Println("Prepare Error: ", err)
	}

	// освобождаем ресурсы в СУБД
	defer stmt.Close()

	// многократно выполняем запрос
	ids := []int{2, 3, 4}
	for _, id := range ids {
		_, err := stmt.Exec(id)
		if err != nil {
			fmt.Println("Exec Error: ", err)
		}
	}
}
