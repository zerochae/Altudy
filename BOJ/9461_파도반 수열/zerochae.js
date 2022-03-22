/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `2
6
12`
).split("\n");
/* get input end */

/* solve */
let t = Number(input.shift());

const dp = new Array(101);
dp[0] = 0;
dp[1] = 1;
dp[2] = 1;
dp[3] = 1;

const solution = () => {
  for (let i = 4; i < dp.length; i++) {
    dp[i] = dp[i - 3] + dp[i - 2];
  }

  return input.map((num) => dp[num]).join("\n");
};

/* solve end */

/* print output */
const output = solution();
console.log(output);
/* print output end */
