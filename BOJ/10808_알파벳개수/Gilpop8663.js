/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `baekjoon`;

const input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let arr = Array.from({ length: 26 }, () => 0);
  for (let i = 0; i < input.length; i++) {
    // console.log(input[i]);
    // console.log(input[i].charCodeAt() - 97);
    arr[input[i].charCodeAt() - 97] += 1;
    // console.log("a".charCodeAt());
  }
  console.log(arr.join(" "));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
