package main

import (
	"context"
	"log"
	"math/rand"
	"sync"
	"time"
)

func longOperation(ctx context.Context) {
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

func SimpleContext() {
	wg := sync.WaitGroup{}
	ctx, _ := context.WithTimeout(context.Background(), 2000*time.Millisecond)
	wg.Add(1)
	go func() {
		longOperation(ctx)
		wg.Done()
	}()

	wg.Wait()
}
