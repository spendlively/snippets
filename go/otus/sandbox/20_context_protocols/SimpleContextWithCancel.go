package main

import (
	"context"
	"log"
	"math/rand"
	"sync"
	"time"
)

func longOper(ctx context.Context) {
	//Задаем seed
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	timer := time.NewTimer(time.Duration(r.Intn(4000)) * time.Millisecond)
	select {
	case <-timer.C:
		log.Println("Work is done")
	case <-ctx.Done():
		log.Println("Finished by context timeout")
	}
}

func SimpleContextWithCancel() {
	wg := sync.WaitGroup{}
	ctx, cancel := context.WithTimeout(context.Background(), 2000*time.Millisecond)
	wg.Add(1)
	go func() {
		longOper(ctx)
		wg.Done()
	}()

	//Передает данные в канал ctx.Done()<-
	cancel()
	log.Println("Finished by cancel")

	wg.Wait()
}

//Finished by cancel
//Finished by context timeout