//Struct
package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

func main() {
	fmt.Println(Vertex{1, 2})
	fmt.Println(Vertex.X)
	fmt.Println(Vertex{X: 1})

	v := Vertex{1, 2}
	p := &v
	p.X = 1e9
	fmt.Println(v)
}



//
