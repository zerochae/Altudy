/* get input */
const absolutes = [4, 7, 12];
const signs = [true, false, true];
/* get input end */

/* solve */
const solution = (absolutes, signs) => {
  return absolutes.reduce(
    (acc, cur, index) => acc + (signs[index] ? cur : cur * -1),0
  );
};
/* solve end */

/* print output */
const output = solution(absolutes, signs);
console.log(output);
/* print output end */
