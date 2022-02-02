package main

import "fmt"

type Queue struct {
	item chan int
}

// Add Queue in Last Index
func (q *Queue) Append(val int) {
	q.item <- val
}

// Remove Queue first Index
func (q *Queue) Pop() int {
	return <-q.item
}

func main() {
	q := Queue{item: make(chan int, 5)}
	q.Append(1)
	q.Append(2)
	q.Append(3)
	q.Append(4)

	a := q.Pop()
	b := q.Pop()
	c := q.Pop()
	d := q.Pop()

	fmt.Println(a)
	fmt.Println(b)
	fmt.Println(c)
	fmt.Println(d)
}
