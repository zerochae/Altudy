/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `5
-1 0 0 1 1
0`
).split("\n");
/* get input end */

const n = Number(input[0]);
const nodes = input[1].split(' ').map(Number);
const target = Number(input[2]);

const solution = (n, nodes, target) => {
  const dfs = (node) => {
    nodes[node] = null;
    for (let i = 0; i < n; i++) {
      if (node === nodes[i]) dfs(i);
    }
  };
  dfs(target);
  return nodes.filter((el, index) => el !== null && !nodes.includes(index)).length;
};

/* print output */
const output = solution(n, nodes, target);
console.log(output);
/* print output end */