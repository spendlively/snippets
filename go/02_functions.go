//Functions
//arguments type goes after its name
package main

import "fmt"

func add(x int, y int) int {
	return x + y
}

func main() {
	fmt.Println(add(42, 13))
}



//2 or more arguments with the same type
x, y int



//Return few results
package main

import "fmt"

func swap(x, y string) (string, string) {
	return y, x
}

func main() {
	a, b := swap("hello", "world")
	fmt.Println(a, b)
}



//named returning values
//use only if function is short
package main

import "fmt"

func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	//return without arguments returns "named returning values"
	return
}

func main() {
	fmt.Println(split(17))
}



//Defer postpone command till the end of function
package main

import "fmt"

func main() {
	defer fmt.Println("world")

	fmt.Println("hello")
}



//postponed calls stored in stack (FILO)
for i := 0; i < 10; i++ {
    defer fmt.Println(i)
}
//9 8 7 6 5 4 3 2 1 0
