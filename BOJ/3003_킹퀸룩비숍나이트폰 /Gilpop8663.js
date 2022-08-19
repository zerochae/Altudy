/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `2 1 2 1 2 1`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let answer = [];
  const chessboard = [1, 1, 2, 2, 2, 8];
  let chessFoundWarehouse = input.map((item) => +item);
  //   console.log(chessFoundWarehouse);
  chessFoundWarehouse.forEach((item, i) => {
    answer.push(chessboard[i] - item);
  });
  console.log(answer.join(" "));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
