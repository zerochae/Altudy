package main

import (
	"bufio"
	"fmt"
	"os"
)

type link struct {
	i    int
	next *link
}

type stack struct {
	top *link
}

func (s *stack) Init() {
	s.top = nil
}

func (s *stack) Push(i int) {
	if s.top == nil {
		s.top = new(link)
		s.top.next = nil
		s.top.i = i
	} else {
		var newLink = new(link)
		newLink.next = s.top
		newLink.i = i
		s.top = newLink
	}
}

func (s *stack) Pop() int {
	if s.top == nil {
		return -1
	} else {
		var ret = s.top.i
		s.top = s.top.next
		return ret
	}
}

func (s *stack) Top() int {
	if s.top == nil {
		return -1
	} else {
		return s.top.i
	}
}

func (s *stack) Empty() int {
	if s.top == nil {
		return 1
	} else {
		return 0
	}
}

func (s *stack) Size() int {
	if s.top == nil {
		return 0
	} else {
		var count = 0
		for x := s.top; x != nil; x = x.next {
			count++
		}
		return count
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	var s = new(stack)
	s.Init()

	var str string
	var dat int
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &str)
		switch str {
		case "push":
			fmt.Fscan(in, &dat)
			s.Push(dat)
		case "top":
			fmt.Fprintln(out, s.Top())
		case "size":
			fmt.Fprintln(out, s.Size())
		case "pop":
			fmt.Fprintln(out, s.Pop())
		case "empty":
			fmt.Fprintln(out, s.Empty())
		}
	}
	out.Flush()
}
