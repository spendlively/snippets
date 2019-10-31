package main

import (
    "fmt"
)

func main () {

    var i interface{} = "qwerty"

    stringValue, isOk := i.(string)
    fmt.Println(stringValue, isOk)

    intValue, isOk := i.(int)
    fmt.Println(intValue, isOk)

    //без использования isOk вызовет ошибку
    //floatValue := i.(float64)
    //fmt.Println(floatValue)

}

