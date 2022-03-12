/* get input */
const input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ");
let N = input[0];
let K = input[1];
/* get input end */

/* solve */
function solution(N, K) {
  let arr = [];

  for (let i = 0; i <= N; i++) {
    if (N % i === 0) {
      arr.push(i);
    }
  }

  return arr[K - 1] === undefined ? 0 : arr[K - 1];
}
/* solve end*/

/* print output */
const output = solution(N, K);
console.log(output);
/* print output end*/
