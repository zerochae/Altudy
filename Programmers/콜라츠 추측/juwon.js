const solution = (num) => {
    if(num === 1) return 0
    let cnt = 0
    const temp = (num) => { 
        if (num % 2 === 0) {
            num = num / 2
        } else { 
            num = num * 3 + 1
        }
        cnt++;
        if (num === 1) {return cnt}
        else if (cnt === 500) {return -1}
        else return temp(num)
    }
    return temp(num)
}
    
console.log(solution(6))


