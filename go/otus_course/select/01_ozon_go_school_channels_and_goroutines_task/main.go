package main

import (
	"fmt"
	"sync"
)

//Необходимо в package main написать функцию
//func Merge2Channels(f func(int) int,in1 <-chan int,in2 <-chan int,out chan <-int,n int)
//Описание ее работы:
//n раз сделать следующее:
//прочитать по одному числу из каждого из двух каналов in1 и in2, назовем их x1 и x2.
//вычислить f(x1) + f(x2)
//записать полученное значение в out
//Функция Merge2Channels должна быть неблокирующей, сразу возвращая управление.
//Функция f может работать долгое время, ожидая чего-либо или производя вычисления.
//Формат ввода
//Количество итераций передается через аргумент n.
//Целые числа подаются через аргументы-каналы in1 и in2.
//Функция для обработки чисел перед сложением передается через аргумент f.
//Формат вывода
//Канал для вывода результатов передается через аргумент out.

func square(i int) int {
	return i * i
}

func Merge2Channels(f func(int) int, in1 <-chan int, in2 <-chan int, out chan<- int, n int) {

	var x1, x2, result int
	var wg sync.WaitGroup

	go func() {
		for i := 0; i < n; i++ {
			wg.Add(1)
			go func() {
				defer wg.Done()
				x1 = <-in1
			}()

			wg.Add(1)
			go func() {
				defer wg.Done()
				x2 = <-in2
			}()

			wg.Wait()

			result += f(x1) + f(x2)
		}

		out <- result
	}()
}

func main() {
	ch1 := make(chan int)
	ch2 := make(chan int)
	out := make(chan int)
	n := 10

	go func() {
		for i := 0; i < n; i++ {
			ch1 <- i
		}
	}()

	go func() {
		for i := 0; i < n; i++ {
			ch2 <- i
		}
	}()

	Merge2Channels(square, ch1, ch2, out, n)

	fmt.Println(<-out)
}
