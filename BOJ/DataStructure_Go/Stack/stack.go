package main

import "fmt"

type Stack []interface{}

// IsEmpty - 스택이 비어있는지 진리값을 반환하는 함수
func (s *Stack) IsEmpty() bool {
	return len(*s) == 0
}

// Push to Stack of End
func (s *Stack) Push(data interface{}) {
	*s = append(*s, data)
	fmt.Printf("%d pushed to Stack of End Index \n", data)
}

// Pop to Stack of End
func (s *Stack) Pop() interface{} {
	if s.IsEmpty() {
		fmt.Println("Stack is empty")
		return nil
	} else {
		lastIdx := len(*s) - 1
		// lastIdx 위치에 있는 값을 가져옴
		data := (*s)[lastIdx]
		// Stack에 마지막 데이터를 제거한다
		*s = (*s)[:lastIdx]

		return data
	}

}

func main() {
	var s Stack
	s.Push(1)
	s.Push(2)
	s.Push(3)
	fmt.Printf("%d poped from stack \n", s.Pop())
	fmt.Println("Show Stack Array Element ", s)
}
