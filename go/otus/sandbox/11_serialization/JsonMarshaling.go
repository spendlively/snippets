package main

import (
	"encoding/json"
	"fmt"
)

type Person struct {
	Name string
	//Важно
	//json.Marshal работает через рефлексию и не видит приватные поля
	age int
	Job struct {
		Department string
		Title      string
	}
}

func JsonMarshaling() {
	p1 := &Person{
		Name: "Vasya",
		age:  36,
		Job: struct {
			Department string
			Title      string
		}{Department: "Operations", Title: "Boss"},
	}
	j, err := json.Marshal(p1)
	if err != nil {
		fmt.Printf("%v\n", err)
		return
	}
	fmt.Printf("p1 json %s\n", j)
	var p2 Person
	json.Unmarshal(j, &p2)
	fmt.Printf("p2: %v\n", p2)
}
