package main

import (
	"bufio"
	"fmt"
	"os"
)

type queue struct {
	curPos  int
	initPos int
}

func main() {
	// type Reader interface {
	//         Read(p []byte) (n int, err error)
	// }

	// type Writer interface {
	//         Write(p []byte) (n int, err error)
	// }

	// io.Reader 인터페이스로 io.Reader 인터페이스를 따르는 읽기 인스턴스 생성
	reader := bufio.NewReader(os.Stdin)
	// io.writer 인터페이스로 io.Writer 인터페이스를 따르는 쓰기 인스턴스 생성
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m int
	// Fscanln => os의 입력, 출력값을 그대로 문자열로 만든뒤 \n를 붙인다. ( 후에 저장? )
	fmt.Fscanln(reader, &n, &m)

	var q []queue
	for i := 0; i < n; i++ {
		// 임시 queue를 만들어 q를 재정의
		temp := queue{}
		temp.curPos = i + 1
		temp.initPos = i + 1
		q = append(q, temp)
	}
	var selectPos []int
	for i := 0; i < m; i++ {
		var pos int
		// %d 정수형
		// %f 실수형 double
		fmt.Fscanf(reader, "%d ", &pos)
		selectPos = append(selectPos, pos)
	}
	var cnt int
	// selectPos의 길이가 0 보다 클떄까지 혹은 q의 길이가 0보다 클때 까지
	for len(selectPos) > 0 && len(q) > 0 {
		for i := 0; i < len(q); i++ {
			// 타겟의 [0]값과 q의 i 번째 initpos의 값이 같은 경우
			if q[i].initPos == selectPos[0] {
				// i가 q의 길이 - i 보다 클때만
				if i < len(q)-i {
					cnt += i
					q = moveLeft(q, i)
				} else {
					cnt += (len(q) - i)
					q = moveRight(q, len(q)-i)
				}
				// q의 길이를 하나 자른다
				q = q[1:]
				// selectPos길이를 하나 자른다 (idx 0번째를 없앰)
				selectPos = selectPos[1:]
				break
			}
		}
	}
	// 출력값을 문자열로 만들어 출력
	fmt.Fprintln(writer, cnt)

}

// q의 길이 - interval 값 부터 q의 길이까지, q의 0부터 q의 길이 - interval 까지 append
func moveRight(q []queue, interval int) []queue {
	q = append(q[len(q)-interval:len(q)], q[0:len(q)-interval]...)
	return q
}

// q의 interval부터 끝까지, q의 idx 0부터 interval 까지 append
func moveLeft(q []queue, interval int) []queue {
	q = append(q[interval:], q[0:interval]...)
	return q
}
