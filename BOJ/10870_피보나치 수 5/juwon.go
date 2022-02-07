package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int

	fmt.Fscanln(reader, &n)

	// fmt.Println(reflect.TypeOf(n))

	var fibonacci = make([]int, n+1)

	for i := 0; i < len(fibonacci); i++ {
		if i == 0 {
			fibonacci[i] = 0
		} else if i == 1 {
			fibonacci[i] = 1
		} else {
			fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]
		}
	}
	fmt.Println(fibonacci[n])
}
