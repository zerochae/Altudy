/* get input */
const n = [3, 1, 2, 3]; // output = 2
// const n = [3, 3, 3, 2, 2, 4]; // output = 3
// const n = [3, 3, 3, 2, 2, 2]; // output = 2
/* get input end */

/* solve */
function solution(nums) {
  let arr = [];
  let cnt = nums.length / 2;

  for (let i = 0; i < nums.length; i++) {
    if (arr.indexOf(nums[i]) === -1) {
      arr.push(nums[i]);
    }
  }

  return arr.length >= cnt ? cnt : arr.length;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
