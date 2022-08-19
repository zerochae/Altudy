/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `3 1 2`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  input = input.sort((a, b) => a - b);
  console.log(input.join(" "));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
