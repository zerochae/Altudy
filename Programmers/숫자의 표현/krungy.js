/* get input */
const n = 15; // output = 4
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  for (let i = 1; i <= n; i++) {
    let sum = i;
    for (let j = i + 1; sum <= n; j++) {
      sum += j;
      if (sum === n) {
        answer++;
      }
    }
  }
  return answer + 1;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
