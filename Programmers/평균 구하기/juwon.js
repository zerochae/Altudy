const arr = [1, 2, 3, 4]

const solution = (arr) =>  arr.reduce((sum, val) =>  sum += val, 0) / arr.length

console.log(solution(arr))