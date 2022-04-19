/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `7 3`;

let input = filePath
  .toString()
  .trim()
  .split(" ")
  .map((item) => +item);
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";
  //   console.log(input);
  const [n, m] = input;
  let arr = Array.from({ length: n }, (v, i) => i + 1);
  //   console.log(arr);
  let t = 0;
  let answer = [];
  while (arr.length) {
    t += m - 1;
    t = t % arr.length;
    const a = arr.splice(t, 1);
    if (a.length) {
      answer.push(...a);
    }
    // console.log(arr, t);
  }
  //   console.log(answer);
  console.log(`<${answer.join(", ")}>`);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
