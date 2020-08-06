package main

import (
	"fmt"
	"reflect"
)

func ReflectValue(){
	var i int = 42
	value := reflect.ValueOf(i)

	fmt.Println(value) //42
	fmt.Println(value.Type()) //int
	fmt.Println(value.Kind()) //int
	fmt.Println(value.Interface()) //42
	fmt.Println(value.Int()) //42
	fmt.Println(value.String()) //<int Value>
	fmt.Println(value.CanSet()) //false
	//value.SetInt()
	//value.Elem()
}

func assertString(iv interface{}) (string, bool) {
	rv := reflect.ValueOf(iv)
	s := ""
	ok := false
	if rv.Kind() == reflect.String {
		s = rv.String()
		ok = true
	}
	return s, ok
}

func ReflectValueTypeAssertion(){
	var iv interface{} = "hello"
	s, ok := assertString(iv)
	fmt.Println(s, ok)
	s2, ok := assertString(42)
	fmt.Println(s2, ok)
}