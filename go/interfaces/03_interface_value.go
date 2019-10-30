package main

import (
    "fmt"
)

type I interface {
    foo() string
}

///////////////////////

type C struct {
    P string
}

///////////////////////

func (c C) foo () string {
    return c.P
}

func main () {

    var i I = C{"class"}

    //Интерфейсное значение:
    //пара из значения и конкретного типа
    fmt.Printf("%v, %T\n", i, i)
}
