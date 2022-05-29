/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `12 5
// 1 5 2 3 6 2 3 7 3 5 2 6`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let answer = "";
  input[0] = input[0].split(" ");
  const N = input[0][0];
  const L = input[0][1];
  input[1] = input[1].split(" ");
  for (let i = 0; i < N; i++) {
    const query = input[1][i];
    let A = i - L + 1 > 0 ? i - L + 1 : 0;
    // console.log(A);
    let minNum = Number.MAX_SAFE_INTEGER;
    for (let j = A; j <= i; j++) {
      //   console.log(input[1][j], j);
      minNum = Math.min(minNum, input[1][j]);
    }
    answer += `${minNum} `;
    // console.log(minNum);
    // console.log(input[1][i]);
  }
  console.log(answer);
}; /* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
