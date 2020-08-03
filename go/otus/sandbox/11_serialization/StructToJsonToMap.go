package main

import (
	"encoding/json"
	"fmt"
)

func StructToJsonToMap() {

	//Поскольку страуктура и map преобразовываются в json одинакового вида
	//мы можем преобразовать структуру в map и наоборот

	j := []byte(`{"Name":"Vasya","Job":{"Department":"Operations","Title":"Boss"}}`)
	var p2 interface{}
	json.Unmarshal(j, &p2)
	fmt.Printf("p2: %v\n", p2)
	person, ok := p2.(map[string]interface{})
	if ok {
		fmt.Printf("name=%s\n", person["Name"])
	}
}
