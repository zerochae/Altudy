/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux" ? fs.readFileSync("/dev/stdin").toString() : `10`
).split("\n");
/* get input end */

/* solve */
const n = Number(input.shift());
const dp = new Array(n + 1).fill(0);

const solution = () => {
  for (let i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (i % 2 === 0) dp[i] = Math.min(dp[i / 2] + 1, dp[i]);
    if (i % 3 === 0) dp[i] = Math.min(dp[i / 3] + 1, dp[i]);
  }

  return dp[n];
};

/* solve end */

/* print output */
const output = solution();
console.log(output);
/* print output end */
