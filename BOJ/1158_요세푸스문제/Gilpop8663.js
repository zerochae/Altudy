/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `7 3`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */

// //solve 1
// const solution = (input) => {
//   "use strict";
//   const n = +input[0];
//   const target = +input[1];
//   let answer = [];
//   let arr = Array.from({ length: n }, (v, i) => i + 1);
//   // console.log(arr);
//   arr.unshift(0);
//   let index = 1;
//   let cnt = 1;

//   for (let i = 0; i < n; i++) {
//     cnt = 1;
//     while (cnt <= target) {
//       // console.log(index, arr[index]);
//       if (arr[index] > 0) {
//         if (cnt === target) {
//           answer.push(arr[index]);
//           arr[index] = 0;
//         }
//         cnt++;
//         if (index === n) {
//           index = 1;
//         } else {
//           index++;
//         }
//       } else if (arr[index] === 0) {
//         if (index === n) {
//           index = 1;
//         } else {
//           index++;
//         }
//       }
//     }

//     // console.log(index);
//   }
//   answer = answer.join(", ");
//   console.log(`<${answer}>`);
//   // console.log(arr);
// };

//solve 2
const solution = (input) => {
  "use strict";
  const n = +input[0];
  const target = +input[1];
  let answer = [];

  let arr = Array.from({ length: n }, (v, i) => i + 1);
  let t = 0;
  while (arr.length > 0) {
    // console.log(t);
    t += target - 1;
    // console.log(t);
    t %= arr.length;
    // console.log(t);
    answer.push(arr.splice(t, 1)[0]);
    // console.log(arr, t);
  }
  answer = answer.join(", ");
  console.log(`<${answer}>`);
  // console.log(arr);
};

/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
