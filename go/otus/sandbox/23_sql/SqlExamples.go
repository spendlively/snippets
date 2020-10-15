package main

import (
	"context"
	"database/sql"
	"fmt"
	_ "github.com/jackc/pgx/stdlib"
	"log"
	"time"
)

func SqlExamples() {
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
	////////Connection check////////
	////////////////////////////////
	ctx, _ := context.WithTimeout(context.Background(), 2000*time.Millisecond)
	err = db.PingContext(ctx)
	if err != nil {
		fmt.Printf("failed to connect to db: %v", err)
	} else {
		fmt.Println("Connected to db")
	}


	////////////////////////////////
	/////////////Insert/////////////
	////////////////////////////////
	query := `insert into app_alert (id, text, begin_at, end_at) values (nextval('app_alert_id_seq'), $1, $2, $3)`
	// sql.Result
	result, err := db.ExecContext(ctx, query,
		"new message", "2019-12-31", "2019-12-31",
	)

	if err != nil {
		fmt.Printf("failed to connect to db: %v", err)
		return
	}

	//// Авто-генерируемый ID (SERIAL) (not supported)
	//eventId, err := result.LastInsertId() // int64
	//if err != nil {
	//	fmt.Printf("LastInsertId error: %v", err)
	//	return
	//} else {
	//	fmt.Println("Event Id: ", eventId)
	//}

	// Количество измененных строк
	rowsAffected, err := result.RowsAffected() // int64
	if err != nil {
		fmt.Printf("failed to connect to db: %v", err)
		return
	} else {
		fmt.Println("Rows affected: ", rowsAffected)
	}


	////////////////////////////////
	/////////////Select/////////////
	////////////////////////////////
	selectQuery := `
		select id, text
		from app_alert
		where id > $1 and begin_at = $2
	`
	rows, err := db.QueryContext(ctx, selectQuery, 1, "2019-12-31")
	if err != nil {
		fmt.Println("Select error: ", err)
	}
	//Возвращает соединение в пул соединений
	defer rows.Close()

	for rows.Next() {
		var id int64
		var text string
		if err := rows.Scan(&id, &text); err != nil {
			fmt.Println("Scan error: ", err)
		}

		fmt.Printf("%d %s\n", id, text)
	}

	if err := rows.Err(); err != nil {
		fmt.Println("getting results error: ", err)
	}
}

//Объект sql.Rows
// возвращает имена колонок в выборке
//rows.Columns() ([]string, error)

// возвращает типы колонок в выборке
//rows.ColumnTypes() ([]*ColumnType, error)

// переходит к следующей строке или возвращает false
//rows.Next() bool

// заполняет переменные из текущей строки
//rows.Scan(dest ...interface{}) error

// закрывает объект Rows
//rows.Close()

// возвращает ошибку, встреченную при итерации
//rows.Error() error
