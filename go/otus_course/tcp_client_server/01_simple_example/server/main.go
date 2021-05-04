package main

import (
	"fmt"
	"net"
)

func main() {

	l, err := net.Listen("tcp", "127.0.0.1:9999")
	if err != nil {
		panic(err)
	}

	defer func() { _ = l.Close() }()

	for {
		conn, err := l.Accept()
		if err != nil {
			panic(err)
		}

		go func(conn net.Conn) {
			// При отправке сообщения сервер НЕ БЛОКИРУЕТСЯ.
			// Но если сообщение (до переноса строки) будет слишком большое,
			// клиент получит ошибку "bufio.Scanner: token too long"
			bytes := []byte(fmt.Sprintf("Welcome to %s, friend from %s\n", conn.LocalAddr(), conn.RemoteAddr()))
			_, err := conn.Write(bytes)
			if err != nil {
				panic(err)
			}
		}(conn)
	}
}
