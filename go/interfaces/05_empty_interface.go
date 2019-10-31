
package main

import (
    "fmt"
)

type T struct {
    V string
}

func main () {

    //в переменную с типом пустой интерфейс
    //можно присвоить любой тип данных
    var i interface{}

    i = 1
    fmt.Println(i)

    i = "string"
    fmt.Println(i)

    i = T{"value"}
    fmt.Println(i)
    //fmt.Println(i.V) // i.V undefined (type interface {} is interface with no methods)

}
