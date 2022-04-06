/* get input */
const n = 121; // output = 144
// const n = 3; // output = -1
/* get input end */

/* solve */
function solution(n) {
  let sqrtNum = Math.sqrt(n);
  return sqrtNum % 1 === 0 ? (sqrtNum + 1) * (sqrtNum + 1) : -1;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
