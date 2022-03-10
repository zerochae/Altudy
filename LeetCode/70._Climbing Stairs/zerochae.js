const n = 2;

const climbStairs = (n) => {
  const dp = new Array(n + 1).fill(null);

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (const i in dp) {
    dp[i] = dp[i] === null ? dp[i - 1] + dp[i - 2] : dp[i];
  }
  return dp;
};

console.log(climbStairs(n));
