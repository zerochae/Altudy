/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `3 3
// 0 3
// 1 5
// 0 6`;

let input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const [n, room] = input[0].split(" ").map((item) => +item);
  //   console.log(n, room);
  input.shift();
  let arr = Array.from({ length: 6 }, () => []);
  let count = 0;
  for (let i = 0; i < n; i++) {
    const [gender, grade] = input[i].split(" ").map((item) => +item);
    // console.log(gender, grade);
    arr[grade - 1][gender] === undefined
      ? (arr[grade - 1][gender] = 1)
      : (arr[grade - 1][gender] += 1);
  }
  //   console.log(arr);
  for (let i = 0; i < 6; i++) {
    count += arr[i][0] ? Math.ceil(arr[i][0] / room) : 0;
    count += arr[i][1] ? Math.ceil(arr[i][1] / room) : 0;
  }
  console.log(count);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
