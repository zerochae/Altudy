/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `316
// 430
// 643
// 1253`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let sum = input.map((item) => +item).reduce((sum, item) => sum + item);
  //   console.log(sum);
  let answer = "";
  answer += parseInt(sum / 60) + "\n" + (sum % 60);
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
