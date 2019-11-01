package main

import "golang.org/x/tour/reader"

type MyReader struct{}

// TODO: Add a Read([]byte) (int, error) method to MyReader.
func (mr MyReader) Read (b []byte) (int, error){
	n := 1
	for i := range b {
		b[i] = 'A'
		n = n + 1
	}
	return len(b), nil
}


func main() {
	reader.Validate(MyReader{})
}

/*
или так
package main

import "code.google.com/p/go-tour/reader"

type MyReader struct{}

// TODO: Add a Read([]byte) (int, error) method to MyReader.
func (m MyReader) Read(b []byte) (i int, e error) {
    for x := range b {
        b[x] = 'A'
    }
    return len(b), nil
}

func main() {
    reader.Validate(MyReader{})
}
*/
