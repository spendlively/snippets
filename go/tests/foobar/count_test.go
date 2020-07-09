package foobar

import "testing"

func TestCount(t *testing.T){
    s := "qwertye"
    e := 2
    if c := Count(s, 'e'); c != e {
        t.Fatalf("bad count for %s; got %d expected %d", s, c, e)
    }
}

//cd this/dir
//go test
