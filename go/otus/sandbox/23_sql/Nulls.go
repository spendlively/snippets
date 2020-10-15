package main

import (
	"context"
	"database/sql"
	"fmt"
	"time"
)

func Nulls() {

	////////////////////////////////
	/////////////Connect////////////
	////////////////////////////////
	dsn := "postgres://photo_moderation_local:spend860819@localhost:5432/photo_moderation_local"
	//dsn := "user=myuser dbname=mydb sslmode=verify-full password=mypass"
	db, err := sql.Open("pgx", dsn) // *sql.DB
	if err != nil {
		fmt.Println("failed to load driver: ", err)
	}

	var id int64
	var moderatorId, sourceId sql.NullInt64

	ctx, _ := context.WithTimeout(context.Background(), 2000*time.Millisecond)
	err = db.QueryRowContext(ctx, "select id, moderator_id, source_id from app_photo where id = 1").Scan(&id, &moderatorId, &sourceId)

	if err != nil {
		fmt.Println("QueryRow error: ", err)
	}

	if moderatorId.Valid {
		fmt.Println("ModeratorId: ", moderatorId.Int64)
	} else {
		fmt.Println("ModeratorId is null")
	}

	if sourceId.Valid {
		fmt.Println("SourceId: ", sourceId.Int64)
	} else {
		fmt.Println("SourceId is null")
	}
}
