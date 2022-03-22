/* get input */
let num = 3;
/* get input end */

/* solve */
function solution(num) {
  var answer = "";
  if (num % 2 === 0) answer = "Even";
  else answer = "Odd";
  return answer;
}
/* solve end */

/* print output */
console.log(solution(num));
/* print output end */
