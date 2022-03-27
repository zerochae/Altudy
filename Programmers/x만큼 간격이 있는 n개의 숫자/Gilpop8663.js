/* get input */
let x = 2;
let n = 5;
/* get input end */

/* solve */
function solution(x, n) {
  var answer = [];
  for (let i = 1; i <= n; i++) {
    answer.push(x * i);
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(x, n));
/* print output end */
