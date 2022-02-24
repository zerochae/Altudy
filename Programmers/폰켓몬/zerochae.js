/* get input */
let nums = [3, 1, 1, 2, 2, 2, 2, 2];
/* get input end*/

/* solve */
const solution = (nums) => {
  
  return new Set(nums).size > nums.length / 2
    ? nums.length / 2
    : new Set(nums).size;
};
/* solve end*/

/* print output */
const output = solution(nums);
console.log(output);
/* print output end*/
