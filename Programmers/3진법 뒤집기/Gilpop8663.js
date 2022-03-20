/* get input */
const n = 273;
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  const arr = [];
  arr.push(n === 3 ? 1 : n % 3);
  let nums = n;
  while (nums > 3) {
    nums = nums / 3;
    arr.unshift(Math.floor(nums % 3));
    if (nums === 3) {
      arr.unshift(1);
    }
  }
  arr.reverse();
  let multiply = 1;
  for (let i = arr.length - 1; i >= 0; i--) {
    answer += arr[i] * multiply;
    multiply = multiply * 3;
  }

  return answer;
}
/* solve end */

/* print output */
console.log(solution(n));
/* print output end */
