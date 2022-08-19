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
  //   console.log(`.  .   .
  //     |  | _ | _. _ ._ _  _
  //     |/\\(/.|(_.(_)[ | )(/.`);
  const first = `.  .   .`;
  const second = `|  | _ | _. _ ._ _  _`;
  const third = `|/\\|(/.|(_.(_)[ | )(/.`;
  console.log(first + "\n" + second + "\n" + third);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
