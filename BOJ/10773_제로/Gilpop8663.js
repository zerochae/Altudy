/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `10
// 1
// 3
// 5
// 4
// 0
// 0
// 7
// 0
// 0
// 6`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let n = +input[0];
  input.shift();
  let stack = [];
  for (let i = 0; i < n; i++) {
    let str = input[i];
    if (str === "0") {
      stack.pop();
    } else {
      stack.push(+str);
    }
  }
  let sum = stack.reduce((sum, item) => sum + item, 0);
  //   console.log(stack);
  console.log(sum);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
