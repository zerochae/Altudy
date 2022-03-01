/* get input */
const answers = [1, 2, 3, 4, 5, 6, 7, 8, 0];
/* get input end */

/* solve */
const solution = (numbers) => {
  return 45 - numbers.reduce((prev, curr) => prev + curr);
};
/* solve end */

/* print output */
const output = solution(answers);
console.log(output);
/* print output end */
