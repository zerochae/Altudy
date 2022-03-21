/* get input */
const n = 12;
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  for (let i = 0; i < n; i++) {
    if (n % i === 1) {
      answer = i;
      break;
    }
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(n));
/* print output end */
