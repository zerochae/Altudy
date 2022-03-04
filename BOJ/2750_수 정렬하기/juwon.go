package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	reader *bufio.Scanner = bufio.NewScanner(os.Stdin)
	writer *bufio.Writer  = bufio.NewWriter(os.Stdout)
)

func nextInt() int {
	reader.Scan()
	text := reader.Text()
	value, _ := strconv.Atoi(text)
	return value
}

func main() {
	reader.Split(bufio.ScanWords)
	defer writer.Flush()

	N := nextInt()
	arr := make([]int, 0)

	for i := 0; i < N; i++ {
		value := nextInt()
		arr = append(arr, value)
		// boolArr = append(boolArr[1000:], true)
	}

	selectSort(N, arr)
}

func selectSort(N int, arr []int) {
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			if arr[i] > arr[j] {
				temp := arr[j]
				arr[j] = arr[i]
				arr[i] = temp
			}
		}
	}

	for i := 0; i < len(arr); i++ {
		fmt.Println(arr[i])
	}
}
