package main

import (
    "fmt"
)

func switchByTypes (i interface{}) string {

    //switch v := i.(type)
    //можно использовать для определения типа
    switch v := i.(type){
        case int:
            return fmt.Sprintf("%v is int", v)
        case string:
            return fmt.Sprintf("%v is string", v)
        default:
            return fmt.Sprintf("have no idea what is %v", v)
    }

    return "the end"
}

func main () {

    fmt.Println(switchByTypes(1))
    fmt.Println(switchByTypes("qwerty"))
    fmt.Println(switchByTypes(1.2))

    //ошибка
    //i.(type) нельзя использовать за пределами switch
    //в if тоже нельзя использовать
    //var i interface{} = 1
    //fmt.Println(i.(type))
}
