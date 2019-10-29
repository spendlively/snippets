
package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

//метод и структура должны быть в одном пакете
//здесь получатель Vertex используется по значению
//т.е. sum работает с копией объекта
func (v Vertex) sum () int {
    return v.X + v.Y
}

//здесь получатель Vertex используется по указателю
//т.е. функция может изменять его данные
func (v *Vertex) modifyX () {
    v.X = v.X * 2
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

	v3 := Vertex{1, 2}
	v3.modifyX()
	fmt.Println(v3)
}

