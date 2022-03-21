/* get input */
const [A, B] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ");
/* get input end */

/* solve */
function solution(A, B) {
  let answer = 0;
  let arr = [];
  let curNum = 1;
  let curIndex = 0;

  while (arr.length <= 1000) {
    if (curIndex < curNum) {
      arr.push(curNum);
      curIndex++;
    } else {
      curNum++;
      curIndex = 0;
    }
  }

  arr.slice(A - 1, B).forEach((item) => (answer += item));

  return answer;
}
/* solve end*/

/* print output */
const output = solution(A, B);
console.log(output);
/* print output end*/
