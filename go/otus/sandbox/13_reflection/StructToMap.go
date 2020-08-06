package main

import (
	"errors"
	"fmt"
	"reflect"
)

type St struct {
	Name string
	Age  int
}

func structToMap(iv interface{}) (map[string]interface{}, error) {
	v := reflect.ValueOf(iv)
	if v.Kind() != reflect.Struct {
		return nil, errors.New("not a struct")
	}
	t := v.Type()
	mp := make(map[string]interface{})
	for i := 0; i < t.NumField(); i++ {
		field := t.Field(i) // reflect.StructField
		fv := v.Field(i)    // reflect.Value
		mp[field.Name] = fv.Interface()
	}
	return mp, nil
}

func structToMapByPointer(iv interface{}) (map[string]interface{}, error) {
	v := reflect.ValueOf(iv)
	if v.Elem().Kind() != reflect.Struct {
		return nil, errors.New("not a struct")
	}
	t := v.Elem().Type()
	mp := make(map[string]interface{})
	for i := 0; i < t.NumField(); i++ {
		field := t.Field(i) // reflect.StructField
		fv := v.Elem().Field(i)    // reflect.Value
		mp[field.Name] = fv.Interface()
	}
	return mp, nil
}

func structToMapExample() {
	st := St{"Boby", 18}
	mp, err := structToMap(st)
	fmt.Printf("MAP: %#v\nERR: %s\n", mp, err)

	st2 := St{"Boby", 18}
	mp2, err2 := structToMapByPointer(&st2)
	fmt.Printf("MAP: %#v\nERR: %s\n", mp2, err2)
}