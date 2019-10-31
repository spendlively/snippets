package main

import (
    "fmt"
)

type Person struct {
    Name string
    Age int
}


//интерфейс Stringer из пакета fmt
//позволяет переменной любого типа
//описать себя с помощью строки
//type Stringer interface {
//    String() string
//}

func (p Person) String() string {
    return fmt.Sprintf("%v is %v years old", p.Name, p.Age)
}

func main () {

    p1 := Person{"Ivan", 33}
    p2 := Person{"Denis", 31}

    fmt.Println(p1)
    fmt.Println(p2)
}
