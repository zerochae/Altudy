/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `aabbcc
// xxyybb`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let [str1, str2] = input;
  let count = 0;
  let arr1 = Array.from({ length: 26 }, () => 0);
  let arr2 = Array.from({ length: 26 }, () => 0);
  //   console.log(str1, str2);
  for (let j = 0; j < str1.length; j++) {
    arr1[str1.charCodeAt(j) - 97] += 1;
  }
  for (let j = 0; j < str2.length; j++) {
    arr2[str2.charCodeAt(j) - 97] += 1;
  }
  //   console.log(arr1, arr2);
  for (let i = 0; i < 26; i++) {
    if (arr1[i] !== arr2[i]) count += Math.abs(arr2[i] - arr1[i]);
  }
  console.log(count);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
