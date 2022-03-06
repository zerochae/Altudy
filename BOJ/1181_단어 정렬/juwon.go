package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	arr := make([]string, N)

	for i := 0; i < N; i++ {
		reader.Scan()
		arr = append(arr, reader.Text())
	}

	sort.Slice(arr, func(i, j int) bool {
		if len(arr[i]) == len(arr[j]) {
			return arr[i] < arr[j]
		} else {
			return len(arr[i]) < len(arr[j])
		}
	})

	var temp string

	for _, value := range arr {
		if value == temp {
			continue
		}
		fmt.Println(value)
		temp = value
	}
}
