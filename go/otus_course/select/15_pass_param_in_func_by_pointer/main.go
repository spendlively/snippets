package main

import "fmt"

func wrongWay() {
	v := 5
	p := &v
	fmt.Println("Was:", *p)

	func(localP *int) {
		localV := 3
		localP = &localV
	}(p)

	fmt.Println("Now:", *p)
}

func rightWay() {
	v := 5
	p := &v
	fmt.Println("Was:", *p)

	func(localP *int) {
		*localP = 3
	}(p)

	fmt.Println("Now:", *p)
}

func main() {
	fmt.Println("Wrong way:")
	wrongWay()
	fmt.Println("==========")
	fmt.Println("Right way:")
	rightWay()
}
