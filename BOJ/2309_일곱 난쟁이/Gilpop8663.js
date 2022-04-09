/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `20
// 7
// 23
// 19
// 10
// 15
// 25
// 8
// 13`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let answer = [];
  for (let i = 0; i < 9; i++) {
    // console.log(input[i]);
    let arr = [...input];
    for (let j = i + 1; j < 9; j++) {
      arr = [...input];
      //   console.log(i, j);
      arr[i] = 0;
      arr[j] = 0;
      let sum = arr.reduce((sum, item) => sum + +item, 0);
      //   console.log(sum);
      if (sum === 100) {
        answer = [...arr];
        break;
      }
    }
  }
  answer = answer.sort((a, b) => a - b);
  answer.shift();
  answer.shift();

  console.log(answer.join("\n"));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
