/* get input */
const d = [2, 2, 3, 3];
let budget = 10;
/* get input end */

/* solve */
const solution = (d, budget) => {
  return d.sort((a,b)=>a-b).reduce((acc, cur) => {
    budget -= cur;
    return budget >= 0 ? acc+1 : acc;
  }, 0);
};
/* solve end */

/* print output */
const output = solution(d, budget);
console.log(output);
/* print output end */
