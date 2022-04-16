const solution = (x = 2, n = 5) => {
    let answer = []
    answer.push(x)
    for (let i = 1; i < n; i++) { 
        answer.push(answer[answer.length - 1] + x)
    }
    return answer
}
    
console.log(solution())



