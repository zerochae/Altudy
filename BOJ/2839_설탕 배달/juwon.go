package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	count := 0
	fmt.Fscanln(reader, &n)

	for {
		if n%5 != 0 {
			if n < 3 {
				count = -1
				break
			}
			n = n - 3
			count++
		} else {
			break
		}
	}
	if count != -1 {
		count += n / 5
	}
	fmt.Println(count)
}
