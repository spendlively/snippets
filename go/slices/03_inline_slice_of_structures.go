package main

import "fmt"

func main () {

    s := []struct{
        key string
        value string
    }{
        {"1", "one"},
        {"2", "two"},
        {"3", "three"},
    }
    fmt.Println(s)
}
