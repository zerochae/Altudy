/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `5 6`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
// const solution = (input) => {
//   "use strict";
//   let A = BigInt(input[0]);
//   let B = BigInt(input[1]);
//   //   console.log(A < B);
//   let answer = "";
//   let count = A <= B ? Number(B - A).toString() : Number(A - B).toString();
//   answer += count + "\n";

//   if (A <= B) {
//     for (let i = Number(A) + 1; i <= B; i++) {
//       answer += `${i} `;
//     }
//   } else {
//     for (let i = Number(B) + 1; i <= A; i++) {
//       answer += `${i} `;
//     }
//   }
//   console.log(answer);
// };
const solution = (input) => {
  "use strict";
  let A = Number(input[0]);
  let B = Number(input[1]);
  //   console.log(A < B);
  let answer = "";
  let count = Math.abs(A - B) - 1;
  if (A === B) count = 0;
  answer += count + "\n";
  let maxNum = Math.max(A, B);
  let minNum = Math.min(A, B);
  for (let i = minNum + 1; i < maxNum; i++) {
    answer += `${i} `;
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
