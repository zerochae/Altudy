/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `6 2`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let n = BigInt(input[0]);
  let m = +input[1];
  //   console.log(n);
  let p, q;
  for (let i = 2; i < m; i++) {
    // console.log(n % BigInt(i), BigInt(0));
    if (n % BigInt(i) === BigInt(0)) {
      p = i;
      return console.log(`BAD ${+p}`);
    }
  }
  let answer = "GOOD";
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
