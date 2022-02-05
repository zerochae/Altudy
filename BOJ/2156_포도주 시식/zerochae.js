/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : 
`6
6
10
13
9
8
1`
).split("\n");
/* get input end*/

/* set param */
const n = Number(input.shift());
const dp = new Array(n+1).fill(0);
const arr = new Array();

input.map(el => {
  return arr.push(Number(el))
})

dp[1] = arr[0]; // 1개인 경우
dp[2] = dp[1] + arr[1]; // 2개인 경우
/* set param end*/

/* solve */
const solution = (n) => {
  
  /*
  3개 연속 마실 수 없음. 하나 마시고 건너뛰기 or 두개 마시고 건너뛰기 or 마지막꺼 안먹기

  1. 하나만 먹기
  dp[i] = dp[i-2] + arr[i-1];
  
  2. 두개 먹기
  dp[i] = dp[i-3] + arr[i-2] + arr[i-1];

  3. 마지막꺼 안 먹기
  dp[i] = dp[i-1];

  */
 
  if( n >= 3 ) { // 3개 이상 경우부터 DP 
    for(let i = 3; i<=n; i++){
      dp[i] = Math.max(dp[i-2] + arr[i-1],Math.max(dp[i-3] + arr[i - 2] + arr[i - 1],dp[i-1]));
    }
  }
  
  return dp[n];
};
/* solve end*/

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/