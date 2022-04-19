/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `10
// zzzzzzzzzz`;

let input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

//Big Int 풀이

// const solution = (input) => {
//   "use strict";
//   //   console.log(input);
//   const n = +input[0];
//   const str = input[1].split("");
//   let numStr = [];
//   //   console.log(n, str);
//   for (let i = 0; i < n; i++) {
//     // console.log(str[i].charCodeAt() - 96);
//     numStr.push(str[i].charCodeAt() - 96);
//   }
//   //   console.log(numStr);
//   let sum = BigInt(0);
//   for (let i = 0; i < n; i++) {
//     sum += BigInt(numStr[i]) * BigInt(31) ** BigInt(i);
//   }
//   //   console.log(sum);
//   sum = sum % BigInt(1234567891);
//   console.log(Number(sum));
//   //   console.log(area);
// };

// 나머지 계산한 풀이

const solution = (input) => {
  "use strict";
  //   console.log(input);
  const n = +input[0];
  const str = input[1].split("");
  let numStr = [];
  //   console.log(n, str);
  for (let i = 0; i < n; i++) {
    // console.log(str[i].charCodeAt() - 96);
    numStr.push(str[i].charCodeAt() - 96);
  }
  //   console.log(numStr);
  let sum = 0;
  let r = 1;
  for (let i = 0; i < n; i++) {
    sum += numStr[i] * r;
    sum %= 1234567891;
    r *= 31;
    r %= 1234567891;
  }
  //   console.log(sum);
  sum = sum % 1234567891;
  console.log(sum);
  //   console.log(area);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
