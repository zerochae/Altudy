package main

import (
	"bufio"
	"fmt"
	"os"
)

type node struct {
	data int
	link *node
}

type queue struct {
	front *node
	rear  *node
	size  int
}

func (q *queue) Init() {
	q.front = nil
	q.rear = nil
	q.size = 0
}

func (q *queue) Push(x int) {
	if q.size == 0 {
		var newNode = new(node)
		newNode.link = nil
		newNode.data = x
		q.front = newNode
		q.rear = newNode
		q.size++
	} else {
		var newNode = new(node)
		newNode.link = nil
		newNode.data = x
		q.rear.link = newNode
		q.rear = newNode
		q.size++
	}
}

func (q *queue) Pop() int {
	if q.size == 0 {
		return -1
	} else {
		var ret = q.front.data
		q.front = q.front.link
		if q.front == nil {
			q.rear = nil
		}
		q.size--
		return ret
	}
}

func (q *queue) Size() int {
	return q.size
}

func (q *queue) Front() int {
	if q.size == 0 {
		return -1
	} else {
		return q.front.data
	}
}

func (q *queue) Rear() int {
	if q.size == 0 {
		return -1
	} else {
		return q.rear.data
	}
}

func (q *queue) Empty() int {
	if q.size == 0 {
		return 1
	} else {
		return 0
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)

	var input string
	var data int

	var q = new(queue)

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &input)

		switch input {
		case "push":
			fmt.Fscan(in, &data)
			q.Push(data)
		case "pop":
			fmt.Fprint(out, q.Pop())
			if i != n-1 {
				fmt.Fprintln(out)
			}
		case "size":
			fmt.Fprint(out, q.Size())
			if i != n-1 {
				fmt.Fprintln(out)
			}
		case "empty":
			fmt.Fprint(out, q.Empty())
			if i != n-1 {
				fmt.Fprintln(out)
			}
		case "front":
			fmt.Fprint(out, q.Front())
			if i != n-1 {
				fmt.Fprintln(out)
			}
		case "back":
			fmt.Fprint(out, q.Rear())
			if i != n-1 {
				fmt.Fprintln(out)
			}
		}
	}
}
