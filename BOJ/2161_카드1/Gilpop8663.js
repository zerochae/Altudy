/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `7`;

const input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  // console.log(input);
  let stack = [];
  for (let i = 1; i <= +input; i++) {
    stack.push(i);
  }

  while (stack.length === 1 ? false : true) {
    stack.push(stack[1]);
    console.log(stack[0]);
    stack.shift();
    stack.shift();
  }
  console.log(stack[0]);
};

// };
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
