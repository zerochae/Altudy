/* get input */
const n = 12345; // output = [5, 4, 3, 2, 1]
/* get input end */

/* solve */
function solution(n) {
  var answer = [];

  while (n) {
    answer.push(n % 10);
    n = parseInt(n / 10);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
