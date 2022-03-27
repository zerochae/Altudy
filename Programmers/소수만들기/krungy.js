/* get input */
const nums = [1, 2, 3, 4]; // output = 1
// const nums = [1, 2, 7, 6, 4]; // output = 4
/* get input end */

/* solve */
function isAns(pick) {
  let answer = true;

  for (let i = 3; i <= Math.floor(pick / 2); i++) {
    if (pick % i === 0) {
      answer = false;
      break;
    }
  }
  return answer;
}

function solution(nums) {
  let answer = 0;

  for (let i = 0; i < nums.length - 2; i++) {
    for (let j = i + 1; j < nums.length - 1; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        const pick = nums[i] + nums[j] + nums[k];
        const ans = isAns(pick);
        if (ans) answer++;
      }
    }
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(nums);
console.log(output);
/* print output end */
