package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	defer writer.Flush()

	var n int

	fmt.Fscanln(reader, &n)

	dp := make([]int, 11)

	dp[1] = 1

	dp[2] = 2

	dp[3] = 4

	var m int
	for i := 0; i < n; i++ {
		fmt.Fscanln(reader, &m)

		for j := 4; j <= m; j++ {
			dp[j] = dp[j-1] + dp[j-2] + dp[j-3]
		}
		
		fmt.Fprintln(writer, dp[m])
	}

}
