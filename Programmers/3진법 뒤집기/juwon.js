const n  = 45

const solution = (n) =>  parseInt(n.toString(3).split("").reverse().join(""), 3)

const output = solution(n)
console.log(output)