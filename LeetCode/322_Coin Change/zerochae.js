const coins = [1, 2, 5];
const amount = 11;

const coinChange = (coins, amount) => {
  const dp = Array(amount + 1).fill(Infinity);
  dp[0] = 0;
  dp.map((_, i) =>
    coins.map(
      (coin) => i - coin >= 0 && (dp[i] = Math.min(dp[i], dp[i - coin] + 1))
    )
  );
  return dp[amount] !== Infinity ? dp[amount] : -1;
};

console.log(coinChange(coins, amount));
