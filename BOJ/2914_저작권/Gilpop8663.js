/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `10 10`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  //   console.log(input);
  let numberSongs = +input[0];
  let average = +input[1] - 1;
  console.log(numberSongs * average + 1);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
