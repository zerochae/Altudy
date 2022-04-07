/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `3
// ((
// ))
// ())(()`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let n = +input[0];
  input.shift();
  for (let i = 0; i < n; i++) {
    let stack = [];
    let vps = true;
    for (let k = 0; k < input[i].length; k++) {
      //   console.log(input[i][k]);
      let str = input[i][k];
      if ((str === "(") | (str === "[")) {
        stack.push(str);
      } else if (str === "]") {
        if (stack[stack.length - 1] === "[") {
          stack.pop();
        } else {
          vps = false;
          break;
        }
      } else if (str === ")") {
        if (stack[stack.length - 1] === "(") {
          stack.pop();
        } else {
          vps = false;
          break;
        }
      }
    }

    if (stack.length === 0 && vps) {
      console.log("YES");
    } else {
      console.log("NO");
    }
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
