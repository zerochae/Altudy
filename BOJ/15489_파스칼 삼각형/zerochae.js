/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `3 1 4`
).split("\n");
/* get input end*/

/* set param */
const [r, c, w] = input.shift().split(" ").map(el => {
  return Number(el)
});

const dp = new Array(31).fill(null).map((row,index)=>{
  return Array(index+1).fill(null)
});

let result = 0;
/* set param end*/

/* solve */
const solution = (r, c) => {

  return dp[r][c] = (r === c || c === 1) ? 1 : (dp[r][c] === null) ? solution(r - 1, c - 1) + solution(r - 1, c) : dp[r][c];
};

for (let i = 0; i < w; i++) {
  for (let j = 0; j < i+1; j++) {
    result += solution(r + i, c + j);
  }
}
/* solve end*/

/* print output */
const output = result;
console.log(output);
/* print output end*/