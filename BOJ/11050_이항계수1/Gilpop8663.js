/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `5 2`;

const input = filePath
  .toString()
  .trim()
  .split(" ")
  .map((item) => +item);
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  const [n, m] = input;
  let dy = Array.from(Array(35), () => Array(35).fill(0));
  const DFS = (n, r) => {
    if (dy[n][r] > 0) return dy[n][r];
    if (r === 0 || n === r) return 1;
    else {
      return (dy[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r));
    }
  };
  let answer = DFS(n, m);
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
