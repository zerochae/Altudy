/* get input */
const n = 12; // output = 28
// const n = 5; // output = 6
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  let i = 1;
  while (i <= n) {
    if (n % i === 0) {
      answer += i;
    }
    i++;
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
