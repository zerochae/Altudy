/* get input */
const n = require("fs").readFileSync("/dev/stdin").toString().trim();
/* get input end */

/* solve */
function solution(n) {
  let fibonacci = [0, 1];

  for (let i = 2; i <= n; i++) {
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
  }

  return fibonacci[n];
}
/* solve end*/

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
