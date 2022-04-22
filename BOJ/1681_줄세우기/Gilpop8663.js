/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
const filePath = `10 1`;

const input = filePath
  .toString()
  .trim()
  .split(" ")
  .map((item) => +item);
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  const [n, m] = input;
  let num = 0;
  for (let i = 0; i < n; i++) {
    if (num.toString().includes(m) || (num + 1).toString().includes(m)) {
      num++;
      let regExp = new RegExp(`${m}`, "gi");
      //   console.log(regExp);
      num = +num.toString().replace(regExp, `${m + 1}`);
    } else {
      num++;
    }
  }
  console.log(num);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
