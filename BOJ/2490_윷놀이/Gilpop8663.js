/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `0 1 0 1
// 1 1 1 0
// 0 0 1 1`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let answer = "";
  for (let i = 0; i < input.length; i++) {
    input[i] = input[i].split(" ");
    let count = 0;
    for (let j = 0; j < input[i].length; j++) {
      if (input[i][j] === "1") {
        count++;
      }
    }
    if (count === 0) answer += "D";
    else if (count === 1) answer += "C";
    else if (count === 2) answer += "B";
    else if (count === 3) answer += "A";
    else if (count === 4) answer += "E";
    answer += "\n";
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
