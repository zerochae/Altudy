/* get input */
const [n, ...arr] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(/\s+/);
/* get input end */

/* solve */
function solution(n, arr) {
  let answer = 0;

  for (let i = 0; i < n; i++) {
    let isErr = false;
    for (let j = 2; j <= Math.floor(arr[i] / 2); j++) {
      if (arr[i] % j === 0) {
        isErr = true;
        break;
      }
    }
    if (!isErr && arr[i] >= 2) {
      answer++;
    }
  }

  return answer;
}
/* solve end*/

/* print output */
const output = solution(n, arr);
console.log(output);
/* print output end*/
