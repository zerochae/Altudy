const fs = require('fs');
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `3
26 40 83
49 60 57
13 89 99`
)
  .trim()
  .split("\n");

const n = Number(stdin.shift());
const input = stdin.map((arr) => {
  return arr.split(" ").map(Number);
});
const dp = new Array(n).fill(null).map((arr, row_index) =>
  new Array(3).fill(null).map((el, col_index) => {
    if (row_index === 0) return (el = input[row_index][col_index]);
  })
);

const solution = (n) => {
  for (let i = 0; i < 3; i++) {
    solve(n - 1, i);
  }

  return dp[n - 1].reduce((min, val) => {
    return (min = Math.min(min, val));
  }, Number.MAX_VALUE);
};

const solve = (n, index) => {
  if (dp[n][index] === undefined) {
    dp[n][index] =
      index === 0
        ? input[n][index] + Math.min(solve(n - 1, 1), solve(n - 1, 2))
        : index === 1
        ? input[n][index] + Math.min(solve(n - 1, 0), solve(n - 1, 2))
        : input[n][index] + Math.min(solve(n - 1, 0), solve(n - 1, 1));
  }

  return dp[n][index];
};

const output = solution(n);
console.log(output);
