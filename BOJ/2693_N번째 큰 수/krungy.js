/* get input */
const [n, ...arr] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
/* get input end */

/* solve */
function solution(n, arr) {
  let answer = [];
  let convertedArr = arr.map((item) => item.split(" ").map((item) => item * 1));

  for (let i = 0; i < n; i++) {
    let curArr = convertedArr[i].sort((a, b) => b - a);
    answer.push(curArr[2]);
  }

  return answer.join("\n");
}
/* solve end*/

/* print output */
const output = solution(n, arr);
console.log(output);
/* print output end*/
