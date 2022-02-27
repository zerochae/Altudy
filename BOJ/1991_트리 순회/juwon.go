package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

var (
	reader *bufio.Scanner = bufio.NewScanner(os.Stdin)
	writer *bufio.Writer  = bufio.NewWriter(os.Stdout)
	node   *myNode        = nil
)

type myNode struct {
	data  string
	left  *myNode
	right *myNode
}

func main() {
	defer writer.Flush()

	reader.Scan()

	N, _ := strconv.Atoi(reader.Text())

	for i := 0; i < N; i++ {
		reader.Scan()
		s := strings.Split(reader.Text(), " ")
		data, left, right := s[0], s[1], s[2]
		addnode(data, left, right)
	}

	preOrderTraversal(node)
	writer.WriteString("\n")
	inOrderTraversal(node)
	writer.WriteString("\n")
	postOrderTraversal(node)
}

func addnode(data, left, right string) {
	if node == nil {
		if data != "." {
			node = &myNode{data, nil, nil}
		}
		if left != "." {
			node.left = &myNode{left, nil, nil}
		}
		if right != "." {
			node.right = &myNode{right, nil, nil}
		}
	} else {
		searchNode(node, data, left, right)
	}
}

func searchNode(node *myNode, data string, left string, right string) {
	if node == nil {
		return
	} else if node.data == data {
		if left != "." {
			node.left = &myNode{left, nil, nil}
		}
		if right != "." {
			node.right = &myNode{right, nil, nil}
		}
	} else {
		searchNode(node.left, data, left, right)
		searchNode(node.right, data, left, right)
	}
}

func preOrderTraversal(node *myNode) {
	if node != nil {
		writer.WriteString(node.data)
		preOrderTraversal(node.left)
		preOrderTraversal(node.right)
	}
}
func inOrderTraversal(node *myNode) {
	if node != nil {
		inOrderTraversal(node.left)
		writer.WriteString(node.data)
		inOrderTraversal(node.right)
	}
}
func postOrderTraversal(node *myNode) {
	if node != nil {
		postOrderTraversal(node.left)
		postOrderTraversal(node.right)
		writer.WriteString(node.data)
	}
}
