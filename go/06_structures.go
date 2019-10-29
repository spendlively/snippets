
package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

func (v Vertex) sum () int {
    return v.X + v.Y
}

func main() {

    v1 := Vertex{1, 2}
    fmt.Println("v1 =", v1)
    fmt.Println("v1.sum() =", v1.sum())
    fmt.Println("v1.X =", v1.X)
    fmt.Println("Vertex{X: 1} =", Vertex{X: 1})

    v2 := Vertex{1, 2}
	p := &v2
	p.X = 1e9
	fmt.Println("v2 =", v2)
}

