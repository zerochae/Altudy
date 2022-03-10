const a = [1, 2, 3, 4]
const b = [-3, -1, 0, 2]

const solution = (a, b) => a.reduce( (sum, value, index) =>  sum += value * b[index], 0) 

const output = solution(a, b)
console.log(output)