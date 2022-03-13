/* get input */
const [n, ...arr] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(/\s+/);
/* get input end */

/* solve */
function solution(n, arr) {
  let max = arr[0] * 1;
  let min = arr[0] * 1;

  for (let i = 0; i < n; i++) {
    let curNum = arr[i] * 1;
    max = Math.max(max, curNum);
    min = Math.min(min, curNum);
  }

  return `${min} ${max}`;
}
/* solve end*/

/* print output */
const output = solution(n, arr);
console.log(output);
/* print output end*/
