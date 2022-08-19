/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `6 2 5`;

const input = filePath
  .toString()
  .trim()
  .split(" ")
  .map((item) => +item);
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let arr = Array.from({ length: 6 }, () => 0);
  let answer = 0;
  let A = input[0];
  let B = input[1];
  let C = input[2];
  const maxNum = Math.max(A, B, C);
  for (let i = 0; i < 3; i++) {
    arr[input[i] - 1] += 1;
  }
  //   console.log(arr);
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === 3) {
      answer = 10000 + (i + 1) * 1000;
    } else if (arr[i] === 2) {
      answer = 1000 + (i + 1) * 100;
    }
  }

  if (answer === 0) {
    answer = maxNum * 100;
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
