/* get input */
const [n, ...arr] = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
/* get input end */

/* solve */
function solution(n, arr) {
  let answer = "";

  for (let i = 0; i < n; i++) {
    let converted = (arr[i] * 1).toString(2) + "";
    let position = [];
    let index = 0;
    for (let j = converted.length - 1; j >= 0; j--) {
      if (converted[j] === "1") position.push(index);
      index++;
    }
    answer += position.join(" ") + "\n";
  }

  return answer;
}
/* solve end*/

/* print output */
const output = solution(n, arr);
console.log(output);
/* print output end*/
