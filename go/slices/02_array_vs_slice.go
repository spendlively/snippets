package main

import "fmt"

func main () {

    //1.
    //create array
    a1 := [3]int{1,2,3}
    fmt.Printf("%T %v\n", a1, a1)
    //create slice (create array, and get it's splice)
    s1 := []int{1,2,3}
    fmt.Printf("%T %v\n", s1, s1)

    //2.
    a2 := [3]int{1,2,3}
    //нельзя переинициализировать массив
    //a2 = a2[0:2]
    //а срез можно
    s2 := a2[0:] //1 2 3
    s2 = a2[1:] //2 3
    s2 = s2[1:] //3
    fmt.Println(s2)

}
