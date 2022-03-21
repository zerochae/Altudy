/* get input */
const [M, N] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
/* get input end */

/* solve */
function solution(M, N) {
  let answer = [];
  let sum = 0;
  let min = 0;

  for (let i = M; i <= N; i++) {
    let isErr = false;
    for (let j = 2; j <= Math.floor(i / 2); j++) {
      if (i % j === 0) {
        isErr = true;
        break;
      }
    }

    if (!isErr && i >= 2) {
      sum += i;
      if (min === 0) {
        min = i;
      }
    }
  }

  if (sum === 0 && min === 0) {
    return -1;
  }

  answer.push(sum, min);

  return answer.join("\n");
}
/* solve end*/

/* print output */
const output = solution(M, N);
console.log(output);
/* print output end*/
