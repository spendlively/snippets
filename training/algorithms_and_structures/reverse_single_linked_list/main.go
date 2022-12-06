package main

import "fmt"

type List struct {
	first *ListItem
	last  *ListItem
	len   int64
}

func (l *List) push(item ListItem) {

	l.len++

	if l.first == nil {
		l.first = &item
		l.last = &item
		return
	}

	prev := l.last
	prev.next = &item
	l.last = &item
	l.last.next = nil
}

type ListItem struct {
	next  *ListItem
	value interface{}
}

func printList(l List) {
	el := l.first
	var i int64
	for i = 0; i < l.len; i++ {
		if el == nil {
			break
		}

		fmt.Printf("%T %v, ", el.value, el.value)

		el = el.next
	}

	fmt.Println("")
}

func reverseList(l *List) {

	if l.len == 0 || l.len == 1 {
		return
	}

	var first *ListItem = l.first
	var el *ListItem = first
	var prev *ListItem
	var next *ListItem
	var i int64

	for i = 0; i < l.len; i++ {
		next = el.next
		el.next = prev
		prev = el
		el = next
	}

	l.first = l.last
	l.last = first
}

func main() {

	var i int64

	l := List{}
	for i = 0; i < 10; i++ {
		l.push(ListItem{
			next:  nil,
			value: i,
		})
	}

	printList(l)

	reverseList(&l)

	printList(l)
}
