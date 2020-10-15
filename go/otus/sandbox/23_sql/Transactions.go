package main

import (
	"context"
	"database/sql"
	"fmt"
	"log"
	"time"
)

func Transactions() {

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
	//////////Transactions//////////
	////////////////////////////////
	ctx, _ := context.WithTimeout(context.Background(), 2000*time.Millisecond)
	tx, err := db.BeginTx(ctx, nil)
	if err != nil {
		log.Fatal(err)
	}

	// *sql.Tx
	// далее - обычная работа как с *sql.DB
	query := `insert into app_alert (id, text, begin_at, end_at) values (nextval('app_alert_id_seq'), $1, $2, $3)`
	rows, err := tx.ExecContext(ctx, query, "new message1", "2019-12-31", "2019-12-31")
	if err != nil {
		fmt.Println("Exec error: ", err)
	}

	fmt.Println("Rows: ", rows)

	err = tx.Commit()
	//err := tx.Rollback()

	if err != nil {
		fmt.Println("Commit error: ", err)
	}
}
