/* get input */
let n = 123;
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  answer = n
    .toString()
    .split("")
    .reduce((sum, item) => {
      return sum + +item;
    }, 0);

  return answer;
}
/* solve end */

/* print output */
console.log(solution(n));
/* print output end */
