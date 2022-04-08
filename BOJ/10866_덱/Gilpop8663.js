/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `22
// front
// back
// pop_front
// pop_back
// push_front 1
// front
// pop_back
// push_back 2
// back
// pop_front
// push_front 10
// push_front 333
// front
// back
// pop_back
// pop_back
// push_back 20
// push_back 1234
// front
// back
// pop_back
// pop_back`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const n = +input[0];
  let deque = [];
  let answer = "";
  input.shift();
  for (let i = 0; i < n; i++) {
    if (input[i].slice(0, 10) === "push_front")
      deque.unshift(+input[i].slice(11));
    else if (input[i].slice(0, 9) === "push_back")
      deque.push(+input[i].slice(10));
    else if (input[i] === "pop_front") {
      if (deque.length) {
        answer += deque[0] + "\n";
        deque.shift();
      } else answer += -1 + "\n";
    } else if (input[i] === "pop_back") {
      if (deque.length) {
        answer += deque[deque.length - 1] + "\n";
        deque.pop();
      } else answer += -1 + "\n";
    } else if (input[i] === "size") answer += deque.length + "\n";
    else if (input[i] === "empty") {
      if (deque.length) answer += 0 + "\n";
      else answer += 1 + "\n";
    } else if (input[i] === "front") {
      if (deque.length) answer += deque[0] + "\n";
      else answer += -1 + "\n";
    } else if (input[i] === "back") {
      if (deque.length) answer += deque[deque.length - 1] + "\n";
      else answer += -1 + "\n";
    }
  }

  //   console.log(deque);
  console.log(answer);
  //   console.log(queue);
}; /* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
