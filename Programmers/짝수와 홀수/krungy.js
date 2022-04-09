/* get input */
const num = 3; // output = "Odd"
// const num = 4; // output = "Even"
/* get input end */

/* solve */
function solution(num) {
  return num % 2 == 0 ? "Even" : "Odd";
}
/* solve end */

/* print output */
const output = solution(num);
console.log(output);
/* print output end */
