/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `7
6
1 2
2 3
1 5
5 2
5 6
4 7`
).split("\n");
/* get input end */

/* set param */
const n = Number(input.shift());
const t = Number(input.shift());
let result = 0; // 자기 자신(1번 제외)
const arr = [...new Array(n + 1)].map(() => []);
const visit = [...new Array(n + 1)].fill(false);

/* set param end */

/* solve */
const solution = () => {
  for (let i = 0; i < t; i++) {
    const [root, node] = input[i].split(" ").map(Number);
    arr[root].push(node);
    arr[node].push(root);
  }
  visit[1] = true;

  dfs(1);

  return result;
};

const dfs = (v) => {
  for (let node of arr[v]) {
    if (!visit[node]) {
      visit[node] = true;
      result++;
      dfs(node);
    }
  }
};
/* solve end */

/* print output */
const output = solution();
console.log(output);
/* print output end */