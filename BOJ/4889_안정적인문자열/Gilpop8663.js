/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `}{{{}}}{}{{{
// {}{}{}
// {{{}
// }}}}
// ---`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let answer = "";
  for (let i = 0; i < input.length - 1; i++) {
    const query = input[i].split("");
    // console.log(query);
    let stack = [];
    let cnt = 0;
    for (let j = 0; j < query.length; j++) {
      if (query[j] === "{") stack.push(query[j]);
      else {
        if (stack.at(-1) === "{") stack.pop();
        else stack.push(query[j]);
      }
    }
    // console.log(stack);

    for (let j = 1; j < stack.length; j = j + 2) {
      // if(stack[j-1] ==="{") cnt++
      if (stack[j] === "{" && stack[j - 1] === "}") {
        cnt += 2;
      } else if (stack[j] === "{" && stack[j - 1] === "{") cnt++;
      else if (stack[j] === "}" && stack[j - 1] === "}") cnt++;
    }

    // console.log(cnt);
    answer += `${i + 1}. ${cnt}` + "\n";
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
