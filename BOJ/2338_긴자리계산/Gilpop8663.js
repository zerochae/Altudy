/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `1201
// 0`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let A = BigInt(input[0]);
  let B = BigInt(input[1]);
  //   console.log(A, B);
  console.log((A + B).toString());
  console.log((A - B).toString());
  console.log((A * B).toString());
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
