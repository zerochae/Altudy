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

let input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  let answer = "";
  const n = +input[0];
  let arr = Array.from({ length: 2000000 });
  let head = 0;
  let tail = 0;
  for (let i = 1; i < n + 1; i++) {
    const query = input[i];
    // console.log(query.slice(0, 4));
    // console.log(head, tail, query);
    if (query.slice(0, 4) === "push") {
      arr[tail++] = query.split(" ")[1];
    } else if (query.slice(0, 3) === "pop") {
      if (head === tail) answer += "-1" + "\n";
      else answer += arr[head++] + "\n";
    } else if (query.slice(0, 4) === "size") {
      answer += tail - head + "\n";
    } else if (query.slice(0, 5) === "empty") {
      if (head === tail) answer += "1" + "\n";
      else answer += "0" + "\n";
    } else if (query.slice(0, 5) === "front") {
      if (head === tail) answer += "-1" + "\n";
      else answer += arr[head] + "\n";
    } else if (query.slice(0, 4) === "back") {
      if (head === tail) answer += "-1" + "\n";
      else answer += arr[tail - 1] + "\n";
    }
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
