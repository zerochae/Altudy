/* get input */
let nums = [3, 1, 1, 2, 2, 2, 2, 2];
/* get input end*/

/* solve */
function solution(nums) {
  var answer = 0;
  const arr = new Set();
  for (let i = 0; i < nums.length; i++) {
    arr.add(nums[i]);
  }
  //   console.log(arr.size);
  if (nums.length / 2 > arr.size) {
    answer = arr.size;
  } else if (nums.length / 2 <= arr.size) {
    answer = nums.length / 2;
  }
  return answer;
}
/* solve end*/

/* print output */
const output = solution(nums);
console.log(output);
/* print output end*/
