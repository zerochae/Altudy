/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `15
// push 1
// push 2
// front
// back
// size
// empty
// pop
// pop
// pop
// size
// empty
// pop
// push 3
// empty
// front`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const n = +input[0];
  input.shift();
  let answer = "";
  let queue = [];
  for (let i = 0; i < n; i++) {
    // console.log(input[i].slice(0, 4));
    if (input[i][3] === "h") queue.push(+input[i].slice(5));
    else if (input[i] === "pop") {
      if (queue.length) {
        answer += queue[0] + "\n";
        queue.shift();
      } else answer += -1 + "\n";
    } else if (input[i] === "size") answer += queue.length + "\n";
    else if (input[i] === "empty") {
      if (queue.length) answer += 0 + "\n";
      else answer += 1 + "\n";
    } else if (input[i] === "front") {
      if (queue.length) answer += queue[0] + "\n";
      else answer += -1 + "\n";
    } else if (input[i] === "back") {
      if (queue.length) answer += queue[queue.length - 1] + "\n";
      else answer += -1 + "\n";
    }
  }
  console.log(answer);
  //   console.log(queue);
}; /* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
