/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `10
// 5
// 2
// 3
// 1
// 4
// 2
// 3
// 5
// 1
// 7`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const n = +input[0];

  let arr = Array.from({ length: 10001 }, () => 0);

  for (let i = 1; i < input.length; i++) {
    let tmp = +input[i];
    // console.log(tmp);
    arr[tmp]++;
  }

  let answer = "";
  for (let i = 1; i < 10001; i++) {
    for (let j = 0; j < arr[i]; j++) {
      answer += i + "\n";
    }
  }
  console.log(answer);
  //   console.log(input);
}; /* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
