/* get input */
const n = 125;
/* get input end */

/* solve */
const solution = (n) => {
  return parseInt(n.toString(3).split("").reverse().join(""), 3);
};
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
