
//"var" defines a list of variables
package main

import "fmt"

var c, python, java bool

func main() {
	var i int
	var j int = 1
	var k, l int = 2, 3
	fmt.Println(i, j, k, l, c, python, java)
}



//type can be omitted
var c, python, java = true, false, "no!"



//use := to define variables without "var"
c, python, java := true, false, "no!"
//only inside a function



//basic types
// bool
// string
// int  int8  int16  int32  int64
// uint uint8 uint16 uint32 uint64 uintptr
// byte // псевдоним для uint8
// rune // псевдоним для int32
//      // представляет Unicode код
// float32 float64
// complex64 complex128
package main

import (
	"fmt"
	"math/cmplx"
)

var (
	ToBe   bool       = false
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)

func main() {
	fmt.Printf("Type: %T Value: %v\n", ToBe, ToBe)
	fmt.Printf("Type: %T Value: %v\n", MaxInt, MaxInt)
	fmt.Printf("Type: %T Value: %v\n", z, z)
}



//variables get zero-values be default
package main

import "fmt"

func main() {
	var i int
	var f float64
	var b bool
	var s string
	fmt.Printf("%v %v %v %q\n", i, f, b, s)
}



//type cast
i := 42
f := float64(i)
u := uint(f)



//constants (can't be defined with :=)
const Pi = 3.14



//numeric constants has a big accuracy
package main

import "fmt"

const (
	// Create a huge number by shifting a 1 bit left 100 places.
	// In other words, the binary number that is 1 followed by 100 zeroes.
	Big = 1 << 100
	// Shift it right again 99 places, so we end up with 1<<1, or 2.
	Small = Big >> 99
)

func needInt(x int) int { return x*10 + 1 }
func needFloat(x float64) float64 {
	return x * 0.1
}

func main() {
	fmt.Println(needInt(Small))
	fmt.Println(needFloat(Small))
	fmt.Println(needFloat(Big))
}
