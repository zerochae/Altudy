/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `9 0 0 0 0`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  //   console.log(input);
  let answer = 0;
  let result = 0;
  for (let i = 0; i < input.length; i++) {
    result += Number(input[i]) ** 2;
  }
  //   console.log(result);
  answer = result % 10;
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
