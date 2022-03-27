/* get input */
let arr = [5, 5];
/* get input end */

/* solve */
function solution(arr) {
  var answer = 0;
  answer = arr.reduce((sum, item) => sum + item, 0) / arr.length;
  return answer;
}
/* solve end */

/* print output */
console.log(solution(arr));
/* print output end */
