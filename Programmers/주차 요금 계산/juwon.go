package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

type Parking struct {
	carNum   string
	usedTime int
	parkTime int
	fee      int
}

func main() {

	fee := []int{180, 5000, 10, 600}

	rec := []string{"05:34 5961 IN",
		"06:00 0000 IN", "06:34 0000 OUT",
		"07:59 5961 OUT", "07:59 0148 IN",
		"18:59 0000 IN", "19:09 0148 OUT",
		"22:59 5961 IN", "23:00 5961 OUT"}

	sol := solution(fee, rec)

	// for _, ele := range sol {
	// 	fmt.Println(ele)
	// }

	for i := 0; i < len(sol); i++ {
		fmt.Println(sol[i])
	}

}

// Solution func
func solution(fees []int, records []string) []int {
	b_time := fees[0]
	b_fee := fees[1]
	per_time := fees[2]
	per_fee := fees[3]

	park := make(map[string]*Parking)

	for _, record := range records {
		slice := strings.Split(record, " ")

		carNum := slice[1]

		str := strings.Split(slice[0], ":")
		hour, _ := strconv.Atoi(str[0])
		min, _ := strconv.Atoi(str[1])
		parkTime := hour*60 + min

		if slice[2] == "IN" {
			if val, ok := park[carNum]; ok {
				val.parkTime = parkTime
			} else {
				park[carNum] = &Parking{carNum, 0, parkTime, 0}
			}

		} else {
			val := park[carNum]
			val.usedTime += (parkTime - val.parkTime)
			val.parkTime = -1
		}

	}

	for _, p := range park {
		lastTime := 23*60 + 59
		if p.parkTime != -1 {
			p.usedTime += (lastTime - p.parkTime)
			p.parkTime = -1
		}
	}

	carSlice := []*Parking{}
	for _, car := range park {
		carSlice = append(carSlice, car)
	}

	sort.Slice(carSlice, func(i, j int) bool {
		return carSlice[i].carNum < carSlice[j].carNum
	})

	for _, car := range carSlice {
		at := 0
		if car.usedTime-b_time > 0 {
			at = (car.usedTime - b_time) / per_time
			if (car.usedTime-b_time)%per_time > 0 {
				at += 1
			}
		}
		car.fee = b_fee + at*per_fee
	}
	result := []int{}
	for _, car := range carSlice {
		result = append(result, car.fee)
	}

	return result
}

// // Parse time to int
// func getMin(time string) (parsedTime int) {
// 	s := strings.Split(time, ":")
// 	hour := stringToInt(s[0]) * 60
// 	min := stringToInt(s[1])
// 	parsedTime = hour + min
// 	return
// }

// // string to int
// func stringToInt(str string) int {
// 	intValue, _ := strconv.Atoi(str)
// 	return intValue
// }
