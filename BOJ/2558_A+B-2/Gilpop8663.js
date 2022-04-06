/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `1
// 2`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  //   console.log(input);
  let A = +input[0];
  let B = +input[1];
  console.log(A + B);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
