/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `(((()(()()))(())()))(()())`;

const input = filePath.toString().trim().split("");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let answer = 0;
  let bar = [];
  let razer = [];
  for (let i = 0; i < input.length; i++) {
    if (input[i] === "(") {
      if (input[i + 1] === ")") {
        razer.push(input[i]);
      } else {
        bar.push(input[i]);
      }
    } else {
      if (razer.length) {
        razer.pop();
        answer += bar.length;
      } else {
        bar.pop();
        answer++;
      }
      // console.log(bar, razer, answer);
    }
  }
  console.log(answer);
}; /* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
