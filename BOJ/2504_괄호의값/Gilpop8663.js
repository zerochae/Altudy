/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `[([])]([[[[[]]]]])`;

const input = filePath.toString().trim().split("");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let answer = 0;
  let stack = [];
  let error = false;
  let maxCnt = Number.MIN_SAFE_INTEGER;
  for (let i = 0; i < input.length; i++) {
    maxCnt = Math.max(maxCnt, stack.length);
    if (input[i] === "(" || input[i] === "[") stack.push(input[i]);
    else if (input[i] === ")") {
      if (stack[stack.length - 1] === "(") stack.pop();
      else {
        error = true;
        break;
      }
    } else if (input[i] === "]") {
      if (stack[stack.length - 1] === "[") stack.pop();
      else {
        error = true;
        break;
      }
    }
  }

  if (stack.length) {
    error = true;
    stack = [];
  }

  if (!error) {
    let tmp = "";
    for (let i = 0; i < input.length; i++) {
      // console.log(input[i]);
      if (input[i] === "(" && input[i + 1] === ")") {
        stack.push(2);
        i++;
      } else if (input[i] === "[" && input[i + 1] === "]") {
        stack.push(3);
        i++;
      } else {
        if (!isNaN(input[i]) && !isNaN(input[i + 1])) {
          tmp += input[i];
        } else if (tmp !== "" && !isNaN(input[i])) {
          tmp += input[i];
        } else {
          if (tmp !== "") {
            stack.push(+tmp);
            tmp = "";
          }
          stack.push(input[i]);
        }
      }
    }
    // console.log(stack, tmp);
    let j = 0;
    while (j < maxCnt + 5) {
      let arr = [];
      //   console.log(arr, stack, j);
      for (let i = 0; i < stack.length; i++) {
        if (stack[i] === "[" && stack[i + 2] === "]") {
          arr.push(3 * stack[i + 1]);
          i += 2;
        } else if (stack[i] === "(" && stack[i + 2] === ")") {
          arr.push(2 * stack[i + 1]);
          i += 2;
        } else if (!isNaN(stack[i]) && !isNaN(stack[i + 1])) {
          arr.push(+stack[i] + +stack[i + 1]);
          i++;
        } else {
          arr.push(stack[i]);
        }
        // console.log(arr);
      }
      stack = [...arr];
      j++;
    }

    answer = stack.reduce((sum, item) => sum + item);
  }

  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
