/* get input */
const n = 118372; // output = 873211
/* get input end */

/* solve */
function solution(n) {
  let arr = (n + "").split("");
  arr.sort((a, b) => b - a);
  return arr.join("") * 1;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
