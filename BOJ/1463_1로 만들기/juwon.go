package main

import (
	"fmt"
	"strconv"
)

// var arr [10000001]int64
var arr map[int]int = make(map[int]int)

func main() {
	inputData := ""
	fmt.Scanln(&inputData)

	// i의 값을 inputData의 int64형으로 변환함
	i, _ := strconv.Atoi(inputData)

	fmt.Println(makeOne(i))
}

/*
	공식 ( 점화식 )
	dp[n] = dp[n - 1] + 1
	if n % 3 == 0 {return min(dp[n / 3] + 1, dp[n])}
	if n % 2 == 0 {return min(dp[n / 2] + 1, dp[n])}
	return dp[n]
*/

// top-down 방식 => 재귀 호출
func makeOne(param int) int {
	if param == 1 {
		arr[param] = 0
		return 0
	}
	// if param-1 > 0 && arr[param-1] != 0 {
	// 	return arr[param-1]
	// }

	// arr[param] 값이 존재 한다면 바로 return해서 메모리 절약
	if arr[param] != 0 {
		return arr[param]
	}

	arr[param] = makeOne(param-1) + 1

	if param%3 == 0 {
		// temp 임시 변수를 만들어 param의 3으로 나눈 인덱스에 해당하는 값에 + 1 젖아
		temp := makeOne(int(param/3)) + 1

		if temp < arr[param] {
			arr[param] = temp
			return temp
		}

		return arr[param]
	}

	if param%2 == 0 {
		temp := makeOne(int(param/2)) + 1
		if temp < arr[param] {
			arr[param] = temp
			return temp
		}
		return arr[param]
	}

	// 2 또는 3으로 나누어 0이 되지 않는 경우 위의 공식에서 구한 값을 return
	return arr[param]
}
