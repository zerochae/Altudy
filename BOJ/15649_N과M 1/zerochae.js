/* get input */
const fs = require("fs");
const input =
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `4 2`;
/* get input end */

/* solve */
const [n, m] = input.split(" ").map(Number);
const arr = new Array(m);
const visit = new Array(n + 1).fill(false);
const result = [];
const solution = () => {
  dfs(0);
  return result.join("");
};
const dfs = (depth) => {
  if (depth === m) {
    arr.forEach((el) => {
      result.push(el + " ");
    });
    result.push("\n");
    return;
  }

  for (let i = 1; i <= n; i++) {
    if (!visit[i]) {
      visit[i] = true;
      arr[depth] = i;
      dfs(depth + 1);
      visit[i] = false;
    }
  }
};
/* solve end */

/* print output */
const output = solution();
console.log(output);
/* print output end */
