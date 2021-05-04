package main

import (
	"bufio"
	"log"
	"net"
	"sync"
	"time"
)

func main() {

	timeout, err := time.ParseDuration("10s")
	if err != nil {
		panic(err)
	}

	conn, err := net.DialTimeout("tcp", "127.0.0.1:9999", timeout)
	if err != nil {
		panic(err)
	}

	wg := sync.WaitGroup{}
	wg.Add(2)

	go func() {

		scanner := bufio.NewScanner(conn)
		for {

			// 1. Здесь клиент блокируется, пока сервер не напишет сообщение, которое заканчивается на "\n"
			// либо пока scanner.Scan() не вернет false (например при разрыве соединения).
			// 2. Если отправленные сообщения не заканчивается на "\n", клиент будет продолжать ждать "\n".
			// 3. Если сообщение до "\n" будет слишком большое, scanner.Scan() вернет false,
			//а scanner.Err() вернет "bufio.Scanner: token too long".
			if scanner.Scan() {
				// 1. Когда сервер написал, вычитываем одну строку до символа переноса строки "\n".
				// 2. Это может быть одно или более сообщений от сервера.
				text := scanner.Text()
				log.Printf("From server: %s", text)
			} else {
				// Если не удалось прочитать из сокета (Scan() вернул false),
				// проверяем, есть ли ошибка (err != nil)
				// или разрыв соединения - io.EOF (err == nil)
				// scanner.Text() вернет nil
				err := scanner.Err()
				panic(err)
			}
		}

		wg.Done()
	}()

	go func() {
		time.Sleep(10 * time.Second)
		wg.Done()
	}()

	wg.Wait()

	_ = conn
}
