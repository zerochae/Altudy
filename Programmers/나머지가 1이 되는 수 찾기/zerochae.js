/* get input */
const n = 10;
/* get input end */

/* set param */
let x = 0;
/* set param end */

/* solve */
const solution = (n) => {
  while (n % x !== 1) {
    x++;
  }

  return x;
};
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
