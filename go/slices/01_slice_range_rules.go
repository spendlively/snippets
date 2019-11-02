package main

import (
    "fmt"
)

func main () {

    //Срез - это гибкое отображение элементов массива
    //с возможностью динамического изменения размера
    //var array []string = []string{"a", "b", "c", "d", "e"}
    array := []string{"a", "b", "c", "d", "e"}

    splice1 := array[:1] //[0, 1) => a
    fmt.Println(splice1)

    splice2 := array[0:2] //[0, 2) => a b
    fmt.Println(splice2)

    splice3 := array[1:] //[1, last] => b c d e
    fmt.Println(splice3)

}
