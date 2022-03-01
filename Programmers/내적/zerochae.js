/* get input */
const a = [1, 2, 3, 4];
const b = [-3, -1, 0, 2];
/* get input end */

/* solve */
const solution = (a, b) => {
  return a.reduce((acc, cur, index) => acc + cur * b[index], 0);
};
/* solve end */

/* print output */
const output = solution(a, b);
console.log(output);
/* print output end */
