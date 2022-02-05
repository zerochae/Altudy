/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : 
`7` 
).split("\n");
/* get input end*/

/* set param */
const n = Number(input.shift());
const dp = new Array(n+1).fill(null);
dp[3] = dp[5] = 1; // 3kg 일때 1개 , 5kg 일때 1개
/* set param end*/

/* solve */
const solution = (n) => {
  
  if(dp[n] === null){
    return dp[n] = n%5 === 0 ? solution(n-5) + 1: n%3 === 0 ? solution(n-3) + 1 : Math.min(solution(n-5),solution(n-3)) + 1; 
  }

  return dp[n];
};
/* solve end*/

/* print output */
const output = solution(n);
console.log(output === null || isNaN(output) ? -1 : output);
/* print output end*/
