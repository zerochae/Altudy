/* get input */
let n = 121;
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  if (Number.isInteger(Math.sqrt(n)) === true) {
    answer = (Math.sqrt(n) + 1) ** 2;
  } else {
    answer = -1;
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(n));
/* print output end */
