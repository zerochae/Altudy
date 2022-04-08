/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `2
// 29 60`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let n = +input[0];
  input.shift();
  input = input[0].split(" ").map((item) => +item);
  let yArr = [];
  let mArr = [];
  let answer = "";

  for (let i = 0; i < n; i++) {
    // console.log(input[i]);
    yArr.push(Math.ceil((input[i] + 1) / 30) * 10);
    mArr.push(Math.ceil((input[i] + 1) / 60) * 15);
  }
  let ySum = yArr.reduce((sum, item) => sum + item, 0);
  let mSum = mArr.reduce((sum, item) => sum + item, 0);
  //   console.log(yArr, mArr);
  //   console.log(ySum, mSum);
  if (ySum > mSum) answer = `M ${mSum}`;
  else if (ySum < mSum) answer = `Y ${ySum}`;
  else if (ySum === mSum) answer = `Y M ${ySum}`;
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
