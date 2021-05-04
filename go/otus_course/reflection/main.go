package main

import (
	"errors"
	"fmt"
	"reflect"
	"regexp"
)

func parseValidateTag(s string) [][]string {
	re := regexp.MustCompile(`\s*([\w]+)\s*:\s*([^|]+)\s*`)
	return re.FindAllStringSubmatch(s, -1)
}

func Validate(v interface{}) error {

	value := reflect.ValueOf(v)
	fmt.Printf("1. reflect.ValueOf(v): %T = %v\n", value, value)
	//1. reflect.ValueOf(v): reflect.Value = {1234567890}

	valueKind := value.Kind()
	fmt.Printf("2. value.Kind(): %T = %v\n", valueKind, valueKind)
	//2. value.Kind(): reflect.Kind = struct

	if valueKind == reflect.Ptr {
		value = value.Elem()
		fmt.Printf("3. value.Elem(): %T = %v\n", value, value)
		//3. value.Elem(): reflect.Value = {1234567890}
	}

	if value.Kind() != reflect.Struct {
		return errors.New("not a struct")
	}

	valueType := value.Type()
	fmt.Printf("4. value.Type(): %T = %v\n", valueType, valueType)
	//4. value.Type(): *reflect.rtype = main.User

	valueNumField := value.NumField()
	fmt.Printf("5. value.NumField(): %T = %v\n", valueNumField, valueNumField)
	//5. value.NumField(): int = 1

	for i := 0; i < valueNumField; i++ {
		valueField := value.Field(i)
		fmt.Printf("6. value.Field(i): %T = %v\n", valueField, valueField)
		//6. value.Field(i): reflect.Value = 1234567890

		valueTypeField := valueType.Field(i)
		fmt.Printf("7. valueType.Field(i): %T = %v\n", valueTypeField, valueTypeField)
		//7. valueType.Field(i): reflect.StructField = {ID  string json:"id" validate:"min:18|max:50" 0 [0] false}

		fieldTag := valueType.Field(i).Tag
		fmt.Printf("8. valueType.Field(i).Tag: %T = %v\n", fieldTag, fieldTag)
		//8. valueType.Field(i).Tag: reflect.StructTag = json:"id" validate:"min:18|max:50"

		valueTypeFieldType := valueTypeField.Type
		fmt.Printf("9. valueTypeField.Type: %T = %v\n", valueTypeFieldType, valueTypeFieldType)
		//9. valueTypeField.Type: *reflect.rtype = string

		valueTypeFieldName := valueTypeField.Name
		fmt.Printf("10. valueTypeField.Name: %T = %v\n", valueTypeFieldName, valueTypeFieldName)
		//10. valueTypeField.Name: string = ID

		validateTagValue, ok := fieldTag.Lookup("validate")
		fmt.Printf("11. fieldTag.Lookup(\"validate\"): %T = %v\n", validateTagValue, validateTagValue)
		//11. fieldTag.Lookup("validate"): string = min:18|max:50

		if !ok {
			continue
		}

		if validateTagValue == "" {
			continue
		}

		fmt.Printf("%T = %v\n", validateTagValue, validateTagValue) //string = min:18|max:50

		tagParts := parseValidateTag(validateTagValue)
		fmt.Println(tagParts)
	}

	return nil
}

type User struct {
	ID string `json:"id" validate:"min:18|max:50"`
}

func main() {

	user := User{
		ID: "1234567890",
	}

	err := Validate(user)
	if err != nil {
		fmt.Println(err)
	}

	fmt.Println("=======================================")

	err = Validate(&user)
	if err != nil {
		fmt.Println(err)
	}
}
