package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var dp = []int{}
var arr = []int{}

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Sprintln(reader, &n)

	dp = make([]int, n+1)
	arr = make([]int, n+1)

	for i := 1; i < n+1; i++ {
		temp := bufio.NewReader(os.Stdin)
		var tempInt int
		fmt.Sprintln(temp, &tempInt)
		arr[i] = tempInt
	}
	dp[0] = 0
	dp[1] = arr[1]
	if n > 1 {
		dp[2] = arr[1] + arr[2]
	}
	fmt.Println(recur(n))
}

func recur(n int) int {
	if dp[n] == 0 {
		dp[n] = int(math.Max( math.Max(float64(recur(n - 2), float64(recur(n - 3) + arr[n - 1]) + arr[n]), float64(recur(n - 1)) ))
	}
	return dp[n]
}
