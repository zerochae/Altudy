/* get input */
const n = 5;
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  for (let i = 1; i <= n / 2; i++) {
    if (n % i === 0) {
      answer += i;
    }
  }
  answer += n;
  return answer;
}
/* solve end */

/* print output */
console.log(solution(n));
/* print output end */
