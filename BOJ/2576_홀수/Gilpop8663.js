/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `2
// 4
// 20
// 32
// 6
// 10
// 8`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let sum = 0;
  let min = Number.MAX_SAFE_INTEGER;
  for (let i = 0; i < 7; i++) {
    let num = +input[i];
    if (num % 2 === 1) {
      sum += num;
      min = Math.min(min, num);
    }
  }
  let answer = "";
  if (sum === 0) {
    console.log(-1);
  } else {
    console.log(sum + "\n" + min);
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
