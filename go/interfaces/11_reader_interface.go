package main

import (
    "fmt"
    "io"
    "strings"
)

func main () {

    //Интерфейс io.Reader, который представляет
    //сторону потока данных, предназначенную для чтения
    reader := strings.NewReader("This is my long long string!");
    buffer := make([]byte, 8)

    for {
        number, error := reader.Read(buffer)

        //fmt.Printf("%v %v %v\n", number, error, buffer)
        fmt.Printf("%q\n", buffer[:number])

        if error == io.EOF {
            break
        }
    }
}
