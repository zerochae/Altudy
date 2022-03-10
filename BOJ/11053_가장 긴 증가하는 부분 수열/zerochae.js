/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `6
10 20 10 30 20 50`
).split("\n");
/* get input end */

/* set param */
const n = Number(input.shift());
const nums = input[0].split(" ").map(Number);
/* set param end */

/* solve */
const solution = (n, nums) => {

  const dp = new Array(n).fill(null);

  const solve = (n) => {
    if (dp[n] === null) {
      dp[n] = 1;
      for (let i = n - 1; i >= 0; i--) {
        if (nums[i] < nums[n]) dp[n] = Math.max(dp[n], solve(i) + 1);
      }
    }
    return dp[n];
  };
  nums.map((_, i) => {
    solve(i);
  });
  return Math.max(...dp);
};
/* solve end */

/* print output */
const output = solution(n, nums);
console.log(output);
/* print output end */
