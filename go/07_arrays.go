
//arrays
package main

import "fmt"

func main() {
	var a [2]string
	a[0] = "Hello"
	a[1] = "World"
	fmt.Println(a[0], a[1])
	fmt.Println(a)

	primes := [6]int{2, 3, 5, 7, 11, 13}
	fmt.Println(primes)
}



//slices
package main

import "fmt"

func main() {
	primes := [6]int{2, 3, 5, 7, 11, 13}

	var s []int = primes[1:4]
	fmt.Println(s)
    //[3 5 7]
}



//slices are like pointers at the arrays
//it doesn't store any data
//modifying the slice changes the original array
//other slices will see those changes too
//zero-value of slice is nil
names := [4]string{
    "John",
    "Paul",
    "George",
    "Ringo",
}
fmt.Println(names)

a := names[0:2]
b := names[1:3]
fmt.Println(a, b)

b[0] = "XXX"
fmt.Println(a, b)
fmt.Println(names)



//Slices with one border
s := []int{2, 3, 5, 7, 11, 13}

s = s[1:4]
fmt.Println(s)

s = s[:2]
fmt.Println(s)

s = s[1:]
fmt.Println(s)



//length and capacity of the slice
len(s)
cap(s)



//creating a slice using "make"
a := make([]int, 5)
printSlice("a", a)
//[0 0 0 0 0]

b := make([]int, 0, 5) //len(b)=0, cap(b)=5
printSlice("b", b)

c := b[:2]
printSlice("c", c)

d := c[2:5]
printSlice("d", d)



