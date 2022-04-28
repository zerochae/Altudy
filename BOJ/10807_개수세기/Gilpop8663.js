/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `11
// 1 4 1 2 4 2 4 2 3 4 4
// 5`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const n = +input[0];
  input[1] = input[1].split(" ");
  const target = +input[2];
  let count = 0;
  for (let i = 0; i < n; i++) {
    let num = +input[1][i];
    // console.log(num);
    if (num === target) count++;
  }
  console.log(count);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
