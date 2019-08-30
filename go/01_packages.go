//Import few packages
package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(123456)
	fmt.Println("My favorite number is", rand.Intn(10))
	fmt.Println("Time is", time.Now())
}


//Import for each package
import "fmt"
import "math"



//Exporting names always start with capital letter
//If you want to export variable, name it with capital first letter
math.Pi


