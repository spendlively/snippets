package main

import "fmt"
import "project/package1"
import "package2"
import "another-project/package3"

func main(){
    fmt.Println(package1.Function1());
    fmt.Println(package2.Function2());
    fmt.Println(package3.Function3());
}
