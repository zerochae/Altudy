/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `3
// ABAB
// AABB
// ABBA`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  const n = +input[0];
  let answer = 0;
  for (let i = 1; i < input.length; i++) {
    const query = input[i].split("");
    // console.log(query);
    let stack = [];
    for (let j = 0; j < query.length; j++) {
      if (stack.at(-1) === "A" && query[j] === "A") {
        stack.pop();
      } else if (stack.at(-1) === "B" && query[j] === "B") {
        stack.pop();
      } else stack.push(query[j]);
    }
    if (stack.length === 0) {
      answer++;
    }
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
