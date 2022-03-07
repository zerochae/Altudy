/* get input */
const n = 10; // output = 3
// const n = 12; // output = 11
/* get input end */

/* solve */
function solution(n) {
  let i = 1;

  while (i++ < n) {
    if (n % i === 1) {
      break;
    }
  }

  return i;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
