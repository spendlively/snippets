package main

import (
	"fmt"
)

type E struct {
	Msg string
}

func (e E) Error () string {
	return e.Msg
}

//Sqrt должна вернуть не-nil значение ошибки
//когда получает на вход отрицательное число
//т.к. не поддерживает комплексные числа
func Sqrt(x float64) (float64, error) {

	if x < 0 {
		return 0, &E{"x must be greater then 0"}
	}

	return x*x, nil
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}
