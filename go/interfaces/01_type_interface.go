package main

import (
    "fmt"
)

type Inter interface {
    method() string
}

/////////////////////////////////////

type Class1 struct {
    prop string
}

type Class2 struct {
    prop string
}

/////////////////////////////////////

func (c Class1) method () string {
    return c.prop
}

func (c *Class2) method () string {
    return c.prop
}



func main () {

    //class 1 (by value)
    //obj1 := Class1{"class prop 1"}
    //var i1 Inter
    //i1 = obj1
    var i1 Inter = Class1{"class prop 1"}
    fmt.Println(i1.method())

    //class 2 (by pointer)
    var i2 Inter
    var obj2 = Class2{"class prop 2"}
    i2 = &obj2
    fmt.Println(i2.method())
}
