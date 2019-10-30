package main

import (
    "fmt"
)

type I interface {
    printStrings(s string)
}

///////////////////////////////

type C struct {
    P string
}

///////////////////////////////

func (c C) printStrings (s string) {
    fmt.Printf("%s %s\n", c.P, s)
}


func main () {

    //интерфейсы раелизуются неявго
    //поэтому можно реализовать интерфес из другого пакета
    var o I = C{"inside"}
    o.printStrings("outside")
}
