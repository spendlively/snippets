package main

import "fmt"

//Error is
// - a struct, that implements Error interface

type MyStruct struct {
	errorString string
}

func (ms MyStruct) Error() string {
	return ms.errorString
}

func isZero(value int) (bool, error) {

	if value == 0 {
		return true, nil
	}

	//1
	//var ms MyStruct = MyStruct{"Error message"}
	//return false, ms

	//2
	//return false, MyStruct{"Error message"}

	//3
	return false, &MyStruct{"Error message"}
}

func main() {

	fmt.Println("Start")

	fmt.Println(isZero(0))
	fmt.Println(isZero(1))

	fmt.Println("Stop")
}
