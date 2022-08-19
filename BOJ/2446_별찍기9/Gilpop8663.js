/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `5`;

const input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let n = Number(input);
  let answer = "";
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
      answer += " ";
    }

    for (let j = 0; j < 2 * (n - i) - 1; j++) {
      answer += "*";
    }
    answer += "\n";
  }

  for (let i = n - 2; i >= 0; i--) {
    for (let j = 0; j < i; j++) {
      answer += " ";
    }

    for (let j = 0; j < 2 * (n - i) - 1; j++) {
      answer += "*";
    }

    answer += "\n";
  }

  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
