/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `9
// 5 12 7 10 9 1 2 3 11
// 13`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const n = +input[0];
  const target = +input[2];
  let numArr = input[1].split(" ").map((item) => +item);
  let arr = Array.from({ length: target }, () => 0);
  let cnt = 0;

  //   console.log(arr);
  for (let i = 0; i < n; i++) {
    let num = numArr[i];
    if (arr[target - num] === 0) arr[num]++;
    else if (arr[target - num] > 0) {
      cnt++;
    }
  }
  console.log(cnt);
};

/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
