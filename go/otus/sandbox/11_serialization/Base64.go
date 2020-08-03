package main

import b64 "encoding/base64"
import "fmt"

func Base64() {
	data := "Hello world"
	//Std кодировка - для передачи всего
	sEnc := b64.StdEncoding.EncodeToString([]byte(data))
	fmt.Println(sEnc)
	sDec, _ := b64.StdEncoding.DecodeString(sEnc)
	fmt.Println(string(sDec))
	fmt.Println()
	//URL кодировка - для передачи через url
	uEnc := b64.URLEncoding.EncodeToString([]byte(data))
	fmt.Println(uEnc)
	uDec, _ := b64.URLEncoding.DecodeString(uEnc)
	fmt.Println(string(uDec))
}
