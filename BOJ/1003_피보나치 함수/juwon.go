package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n int
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanln(reader, &n)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	for i := 0; i < n; i++ {
		var m int
		fmt.Fscanln(reader, &m)
		initCnt, oneCnt := result(m)
		fmt.Fprintf(writer, "%d %d\n", initCnt[m], oneCnt[m])
	}
}

func result(m int) (initCnt, oneCnt []int) {
	initCnt = []int{1, 0}
	oneCnt = []int{0, 1}

	if m <= 1 {
		return
	}
	for i := 2; i < m+1; i++ {
		initCnt = append(initCnt, initCnt[i-1]+initCnt[i-2])
		oneCnt = append(oneCnt, oneCnt[i-1]+oneCnt[i-2])
	}
	return
}
