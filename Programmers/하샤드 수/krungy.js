/* get input */
const n = 10; // output = true
// const n = 12; // output = true
// const n = 11; // output = false
// const n = 13; // output = false
/* get input end */

/* solve */
function solution(x) {
  let sum = 0;
  let xCpy = x;

  while (xCpy) {
    sum += xCpy % 10;
    xCpy = Math.floor(xCpy / 10);
  }

  return x % sum === 0 ? true : false;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
