/* get input */
let n = 118372;
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  answer = +n
    .toString()
    .split("")
    .sort((a, b) => b - a)
    .map((item) => +item)
    .join("");
  return answer;
}
/* solve end */

/* print output */
console.log(solution(n));
/* print output end */
