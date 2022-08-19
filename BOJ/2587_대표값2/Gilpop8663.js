/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `10
// 40
// 30
// 60
// 30`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let sum = 0;
  let mid = 0;
  input = input.sort((a, b) => a - b);
  for (let i = 0; i < input.length; i++) {
    let num = +input[i];
    // console.log(num);
    sum += num;
  }
  console.log(sum / 5 + "\n" + input[2]);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
