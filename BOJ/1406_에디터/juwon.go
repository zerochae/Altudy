package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"text/template"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var input string
	var n int

	var result string

	fmt.Fscanln(reader, &input, &n)

	left := NewStack()
	right := NewStack()
	splitStr := strings.Split(input, "")

	strList := []string{}

	for _, str := range splitStr {
		strList = append(strList, str)
	}

	for i := 0; i < len(strList); i++ {
		left.Push(strList[i])
	}

	for i := 0; i < n; i++ {
		command := bufio.NewReader(os.Stdin)
		var tempStr string
		fmt.Fscanln(command, &tempStr)
		tempSplitStr := strings.Split(tempStr, " ")
		switch tempStr {
		case "L":
			if left.isEmpty() {
				break
			}
			right.Push(left.Pop())
			break
		case "D":
			if right.isEmpty() {
				break
			}
			left.Push(right.Pop())
			break
		case "B":
			if left.isEmpty() {
				break
			}
			left.Pop()
			break
		case "P":
			left.Push(tempSplitStr[2])
			break
		}
	}
	for !left.isEmpty() {
		right.Push(left.Pop())
	}
	for !right.isEmpty() {
		result = format(result, right.Pop())
	}
	fmt.Println(result)
}

func format(s string, v interface{}) string {
	t, b := new(template.Template), new(strings.Builder)
	template.Must(t.Parse(s)).Execute(b, v)
	return b.String()
}
