/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5`
).split("\n");
/* get input end */

/* set param */
const n = Number(input[0]); input.shift();
const dp = new Array(n); const arr = [];

input.map( (item) => {
  return arr.push(item.split(" ").map((el) => {
    return Number(el);
  }));
})

for(let i = 0; i < n; i ++){
  dp[i] = new Array(i + 1);
}
dp[n-1] = [...arr[n-1]];
/* set param end*/

/* solve */
const solution = (height, index) => {

  if (dp[height][index] === undefined) dp[height][index] = Math.max( solution(height + 1, index), solution(height + 1, index + 1) ) + arr[height][index];
  
  return dp[height][index];
};
/* solve end*/

/* print output */
const output = solution(0,0);
console.log(output);
/* print output end*/