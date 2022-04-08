/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `1 20
// 2 19
// 3 18
// 4 17
// 5 16
// 6 15
// 7 14
// 8 13
// 9 12
// 10 11`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let arr = Array.from({ length: 20 }, (v, i) => i + 1);
  //   console.log(arr);
  //   console.log(input);
  for (let i = 0; i < 10; i++) {
    input[i] = input[i].split(" ");
    let start = input[i][0] - 1;
    let end = input[i][1] - 1;
    for (let j = start; j <= end; j++) {
      //   console.log(arr[j]);
      //   let tmp = arr[start];
      if (start === end) break;
      [arr[start], arr[end]] = [arr[end], arr[start]];
      start++;
      end--;
      //   arr[end] = arr[start];
    }
  }
  console.log(arr.join(" "));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
