/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `6009`;

const input = filePath.toString().trim().split("");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let n = input.length;
  let arr = Array.from({ length: 10 }, (v, i) => 0);
  let max = Number.MIN_SAFE_INTEGER;
  for (let i = 0; i < n; i++) {
    // console.log(input[i]);
    let num = Number(input[i]);

    arr[num] += 1;
  }
  let tmp = arr[6];
  arr[6] = Math.ceil((arr[6] + arr[9]) / 2);
  arr[9] = Math.ceil((tmp + arr[9]) / 2);
  for (let i = 0; i < arr.length; i++) {
    max = Math.max(max, arr[i]);
  }
  //   console.log(arr);
  console.log(max);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
