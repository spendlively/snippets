package main

import (
	"flag"
	"fmt"
)

func Flags(){

	var num = flag.Int("num", 1234, "help message")
	var str = flag.String("str", "default", "help message")

	flag.Parse()

	fmt.Println(num, *num)
	fmt.Println(str, *str)

	//./main -num 1 --str qwerty
	//0xc0000180a8 1234
	//0xc00004a1e0 default

	//./main -num=1 --str=qwerty
	//0xc0000180a8 1234
	//0xc00004a1e0 default
}
