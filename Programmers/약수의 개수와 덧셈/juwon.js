const left  = 24
const right = 27

const solution = (left, right) => {
    let res = 0
    for(let i = left; i <= right; i++){
        // 루트를 씌워 정수이면 true (제곱근의 개수는 홀수), 아니면 false (제곱근의 개수는 짝수) 
        if(Number.isInteger(Math.sqrt(i))){
            res -= i
        } else {
            res += i
        }

    }
    return res
}

const output = solution(left, right)
console.log(output)