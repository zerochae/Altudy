/* get input */
const [...arr] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
/* get input end */

/* solve */
function solution(arr) {
  let answer = 0;
  let cnt = 0;
  for (let i = 0; i < arr.length; i++) {
    let [...tmp] = arr[i].split(" ");
    let out = tmp[0] * 1;
    let take = tmp[1] * 1;
    cnt -= out;
    cnt += take;
    answer = Math.max(answer, cnt);
  }

  return answer;
}
/* solve end*/

/* print output */
const output = solution(arr);
console.log(output);
/* print output end*/
