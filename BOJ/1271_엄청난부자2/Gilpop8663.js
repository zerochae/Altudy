/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `1000 100`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let money = BigInt(input[0]);
  let people = BigInt(input[1]);
  let result = (money / people).toString();
  //   console.log(money / people);
  //   console.log(money % people);
  console.log(result);

  console.log((money % people).toString());
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
