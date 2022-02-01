package main

import "fmt"

func main() {
	param1 := []int{93, 30, 55}
	param2 := []int{1, 30, 5}
	result := solution(param1, param2)
	fmt.Println("result => ", result)
}

func solution(progresses []int, speeds []int) []int {
	var max, count int = 0, 0
	result := []int{}

	for idx, completTime := range progresses {
		var remainPeriod int = 100 - completTime
		var complePeriod int = (remainPeriod / speeds[idx])

		if remainPeriod%speeds[idx] != 0 {
			complePeriod++
		}
		if max < complePeriod {
			result = append(result, count)
			count = 1
			max = complePeriod
		} else {
			count++
		}
	}
	result = append(result[:0], result[1:]...)
	return append(result, count)
}
