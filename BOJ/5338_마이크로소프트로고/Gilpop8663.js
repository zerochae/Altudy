/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = ``;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let logo = `       _.-;;-._
  '-..-'|   ||   |
  '-..-'|_.-;;-._|
  '-..-'|   ||   |
  '-..-'|_.-''-._|`;
  logo = logo.split("\n");
  //   console.log(logo);
  logo.forEach((item, i) => {
    if (i === 0) {
      console.log(item);
    } else {
      console.log(item.trim());
    }
    //   consol``
  });
  /* solve end */
};
/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
