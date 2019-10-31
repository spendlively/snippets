package main

import (
    "fmt"
)

type T struct {
    V string
}

func main () {

    //СХОДСТВА ссылок в c++ и указателей в go

    //1. Указатели не поддерживают арифметику указателей
    a1 := [2]string{"111", "222"}
    var p1 *string
    p1 = &a1[0]
    fmt.Printf("%T %v %v\n", p1, p1, *p1)
    //invalid operation: p1 + 1 (mismatched types *string and int)
    //p1 = p1 + 1
    //fmt.Printf("%T %v %v\n", p1, p1, *p1)


    //2. разыменование может быть опущено
    //при выводе свойства структуры по указателю
    var p2 *T = &T{"value"}
    fmt.Println((*p2).V, p2.V)
    //для простого типа не работает
    var s1 string = "first string"
    var p3 *string = &s1
    fmt.Println((*p3), p3) //first string 0xc00000e210


    //3. Golang не поддерживают умные указатели



    //ОТЛИЧИЯ ссылок в c++ и указателей в go
    //1. Операция получения адреса обязательна при инициализации указателя
    var s2 = "string value"
    var p4 *string
    p4 = &s2
    //p4 = s2 //ошибка: cannot use s (type string) as type *string in assignment
    fmt.Println(*p4)

}