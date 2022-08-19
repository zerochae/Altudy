/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `11 15`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  const R1 = +input[0];
  const S = +input[1];
  const R2 = S * 2 - R1;
  console.log(R2);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
