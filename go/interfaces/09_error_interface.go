package main

import (
    "fmt"
)

type MyError struct {
    Message string
}

func (e MyError) Error () string {
    return fmt.Sprintf("Error with message \"%v\"", e.Message)
}

func getError() error {
    return &MyError{"Sorry"}
}

func main () {

    fmt.Println("Start")

    if v := getError(); v != nil {
        fmt.Println(v)
    }

    fmt.Println("Stop")
}
