/* get input */
let n = 12345;
/* get input end */

/* solve */
function solution(n) {
  var answer = [];
  answer = n
    .toString()
    .split("")
    .reverse()
    .map((item) => +item);
  return answer;
}
/* solve end */

/* print output */
console.log(solution(n));
/* print output end */
