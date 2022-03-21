/* get input */
const arr = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ");
/* get input end */

/* solve */
function solution(arr) {
  const greatest = (a, b) => {
    if (b === 0) return a;
    return greatest(b, a % b);
  };
  const least = (a, b) => (a * b) / greatest(a, b);

  return `${greatest(arr[0], arr[1])}\n${least(arr[0], arr[1])}`;
}
/* solve end*/

/* print output */
const output = solution(arr);
console.log(output);
/* print output end*/
