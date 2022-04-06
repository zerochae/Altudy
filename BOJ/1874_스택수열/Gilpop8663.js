/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `8
// 4
// 3
// 6
// 8
// 7
// 5
// 2
// 1`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  //   console.log(input);
  let answer = [];
  let i = 0;
  let index = 1;
  let stack = [];
  let count = +input[0];
  let sequence = input.slice(1).map((item) => +item);
  //   console.log(sequence);
  //   for (let i = 0; i < count; i++) {}
  while ((index <= count) | stack.length) {
    // console.log(sequence[i], stack[stack.length - 1], index, stack.length);
    if (sequence[i] === stack[stack.length - 1]) {
      stack.pop();
      i++;
      answer.push("-");
    } else if (sequence[i] !== stack[stack.length - 1]) {
      stack.push(index);
      index++;
      answer.push("+");
    }
    if (index > count + 1) break;
    // index++;
  }
  if (stack.length) {
    console.log("NO");
  } else {
    console.log(answer.join("\n"));
  }
};
// };
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
