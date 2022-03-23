/* get input */
const a = 3;
const b = 5; // output = 12
// const a = 3;
// const b = 3; // output = 3
// const a = 5;
// const b = 3; // output = 12

/* get input end */

/* solve */
function solution(a, b) {
  var answer = 0;
  let [min, max] = [Math.min(a, b), Math.max(a, b)];
  for (let i = min; i <= max; i++) {
    answer += i;
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(a, b);
console.log(output);
/* print output end */
