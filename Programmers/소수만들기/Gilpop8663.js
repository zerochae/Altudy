/* get input */
const nums = [1, 2, 7, 6, 4];
/* get input end */

/* solve */

function solution(nums) {
  var answer = 0;
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        sum = nums[i] + nums[j] + nums[k];
        // console.log(sum);
        // console.log(decimalFn(sum));
        if (decimalFn(sum) === true) {
          answer++;
        }
      }
    }
  }
  return answer;
}

function decimalFn(sum) {
  let check = true;
  for (let m = 2; m <= Math.sqrt(sum); m++) {
    if (sum % m === 0) {
      check = false;
    }
  }
  return check;
}
/* solve end */

/* print output */
console.log(solution(nums));
/* print output end */
