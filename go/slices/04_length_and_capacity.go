package main

import "fmt"

func main () {

    a1 := [3]int{1,2,3}
    s1 := a1[0:2]

    fmt.Println("s1 =", s1) //1, 2
    fmt.Println("length =", len(s1)) //2 (1 and 2)
    fmt.Println("capacity =", cap(s1)) //3 (len(a1) from 0)

    s2 := a1[0:1]
    fmt.Println(len(s2), cap(s2)) //1, 3

    //Размер среза может быть увеличен путем повторной операции "срезания"
    //при условии, что он обладает достаточной вместимостью
    s3 := a1[:0] //[]
    s3 = s3[:1] //[1]
    s3 = s3[:2] //[1,2]
    s3 = s3[:3] //[1,2,3]
    fmt.Println(s3)
}
