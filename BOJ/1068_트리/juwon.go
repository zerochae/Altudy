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
	res                   = 0
)

func main() {
	reader.Split(bufio.ScanWords)
	defer writer.Flush()

	N := nextInt()

	root := -1

	mytree := make([][]int, N)

	for i := 0; i < N; i++ {
		v := nextInt()
		if v == -1 {
			root = i
		} else {
			mytree[v] = append(mytree[v], i)
		}
	}

	deleteNode := nextInt()

	if deleteNode == root {
		fmt.Fprintln(writer, 0)
		return
	}

	countLeaf(mytree, root, deleteNode)

	fmt.Fprintln(writer, res)
}

func countLeaf(mytree [][]int, root, deleteNode int) {
	temp := 1
	for _, value := range mytree[root] {
		if value == deleteNode {
			continue
		}
		temp = 0
		countLeaf(mytree, value, deleteNode)
	}

	res += temp

}

func nextInt() int {
	reader.Scan()
	text := reader.Text()
	value, _ := strconv.Atoi(text)
	return value
}
