//go has only for
package main

import "fmt"

func main() {
	sum := 0
	//"for" has no parentheses
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)
}



//without options
for ; sum < 1000; {
    sum += sum
}



//while-style
sum := 1
for sum < 1000 {
    sum += sum
}



//endless loop
for {
}



//if (without parentheses too)
if x < 0 {
    //...
}



//if can starts with instructions,
//that will be executed before comparing
if v := math.Pow(x, n); v < lim {
    return v
}
//v exists inside if block only



//if-else
if q == 0 {
    fmt.Println(0)
} else if q == 1 {
    fmt.Println(1)
} else {
    fmt.Println(2)
}



//switch
package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Print("Go runs on ")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd,
		// plan9, windows...
		fmt.Printf("%s.", os)
	}
}



//switch without condition and switch true are equivalent
t := time.Now()
switch {
    case t.Hour() < 12:
        fmt.Println("Good morning!")
    case t.Hour() < 17:
        fmt.Println("Good afternoon.")
    default:
        fmt.Println("Good evening.")
}
