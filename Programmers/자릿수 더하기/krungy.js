/* get input */
const n = 123; // output = 6
// const n = 987; // output = 24
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;

  while (n) {
    answer += n % 10;
    n = parseInt(n / 10);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
