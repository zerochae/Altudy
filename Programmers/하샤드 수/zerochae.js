const x = 10;

const solution = (x) => x % String(x).split("").reduce((acc,cur)=> acc+Number(cur),0) === 0

const output = solution(x)
console.log(output);