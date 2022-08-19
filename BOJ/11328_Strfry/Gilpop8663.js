/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `4
// caa
// acbd bacd
// ring gnir
// twanssa twanssa`;

let input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const n = +input[0];
  for (let i = 1; i <= n; i++) {
    const arr = Array.from({ length: 26 }, () => 0);
    const [str1, str2] = input[i].split(" ");
    for (let j = 0; j < str1.length; j++) {
      arr[str1.charCodeAt(j) - 97]++;
      arr[str2.charCodeAt(j) - 97]--;
    }
    if (arr.some((v) => v !== 0)) console.log("Impossible");
    else console.log("Possible");
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
