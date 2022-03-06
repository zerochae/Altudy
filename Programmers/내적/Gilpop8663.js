/* get input */
const a = [1, 2, 3, 4];
const b = [-3, -1, 0, 2];
/* get input end */

/* solve */
function solution(a, b) {
  var answer = 1234567890;
  let sum = 0;
  for (let i = 0; i < a.length; i++) {
    sum += a[i] * b[i];
  }
  answer = sum;
  return answer;
}
/* solve end */

/* print output */
const output = solution(a, b);
console.log(output);
/* print output end */
