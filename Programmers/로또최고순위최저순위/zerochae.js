/* get input */
const lottos = [44, 1, 0, 0, 31, 25];
const win_nums = [31, 10, 45, 1, 6, 19];
/* get input end*/

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
