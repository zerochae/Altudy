/* get input */
const a = [1, 2, 3, 4];
const b = [-3, -1, 0, 2]; // output = 3
// const a = [-1, 0, 1];
// const b = [1, 0, -1]; // output = -2
/* get input end */

/* solve */
function solution(a, b) {
  let answer = 0;

  for (let i = 0; i < a.length; i++) {
    answer += a[i] * b[i];
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(a, b);
console.log(output);
/* print output end */
