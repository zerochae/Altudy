/* get input */
let num = 626331;
/* get input end */

/* solve */
function solution(num) {
  var answer = 0;
  while (num > 1) {
    if (num % 2 === 0) {
      num = num / 2;
    } else num = num * 3 + 1;
    answer++;
  }
  if (answer > 500) answer = -1;
  return answer;
}
/* solve end */

/* print output */
console.log(solution(num));
/* print output end */
