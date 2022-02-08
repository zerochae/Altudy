package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var str1 []string
var str2 []string
var dp [][]int

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Fscanln(reader, &str1, &str2)

	dp = make([][]int, len(str1), len(str2))

	fmt.Println(LCS(len(str1)-1, len(str2)-1))
}

func LCS(x, y int) int {
	if x == -1 || y == -1 {
		return 0
	}

	if dp[x][y] == 0 {
		dp[x][y] = 0
		if str1[x] == str2[y] {
			dp[x][y] = LCS(x-1, y-1) + 1
		} else {
			dp[x][y] = int(math.Max(float64(LCS(x-1, y)), float64(LCS(x, y-1))))
		}
	}
	return dp[x][y]
}
