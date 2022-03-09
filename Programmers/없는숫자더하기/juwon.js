const numbers = [5,8,4,0,6,7,9,0]

const solution = (numbers) => numbers.reduce( (sum, value) => sum -= value, 45) 

const output = solution(numbers)

console.log(output)