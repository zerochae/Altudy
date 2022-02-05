/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : 
`5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5`
).split("\n");
/* get input end */

/* set param */
const n = Number(input.shift());

const dp = new Array(n).fill(null).map((row,index)=>{
  return new Array(index+1).fill(null);
})

const arr = new Array(n).fill(null).map((row,index) => {
  return input[index].split(" ").map(Number)
})

dp[n-1] = [...arr[n-1]];
/* set param end*/

/* solve */
const solution = (height, index) => {

  return dp[height][index] = dp[height][index] === null ? dp[height][index] = Math.max( solution(height + 1, index), solution(height + 1, index + 1) ) + arr[height][index] : dp[height][index];
};
/* solve end*/

/* print output */
const output = solution(0,0);
console.log(output);
/* print output end*/