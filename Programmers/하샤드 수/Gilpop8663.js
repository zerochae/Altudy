/* get input */
let x = 10;
/* get input end */

/* solve */
function solution(x) {
  var answer = true;
  let numSum = x
    .toString()
    .split("")
    .reduce((sum, item) => sum + +item, 0);
  answer = x % numSum === 0 ? true : false;
  return answer;
}
/* solve end */

/* print output */
console.log(solution(x));
/* print output end */
