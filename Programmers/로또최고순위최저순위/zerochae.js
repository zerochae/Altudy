/* get input */
// const lottos = [0, 0, 0, 0, 0, 0];
// const win_nums = [38, 19, 20, 40, 15, 25];
const lottos = [44, 1, 0, 0, 31, 25];
const win_nums = [31, 10, 45, 1, 6, 19];
// const lottos = [45, 4, 35, 20, 3, 9];
// const win_nums = [45, 4, 35, 20, 3, 9];
/* get input end*/

/* set param */

/* set param end*/

/* solve */
const solution = (lottos, win_nums) => {
  const zero = lottos.filter((el) => el === 0).length;
  const match = lottos.filter((el) => win_nums.includes(el)).length;

  return match === 0 && zero === 0
    ? [6, 6]
    : [7 - (zero + match), match === 0 ? 6 : 7 - match];
};
/* solve end*/

/* print output */
const output = solution(lottos, win_nums);
console.log(output);
/* print output end*/
