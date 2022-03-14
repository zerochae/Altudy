/* get input */
const arr = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
/* get input end */

/* solve */
function solution(arr) {
  let answer = "";
  let sum = 0;
  let convertedArr = arr.map((item) => {
    sum += item * 1;
    return item * 1;
  });

  for (let i = 0; i < convertedArr.length - 1; i++) {
    let isFind = false;
    for (let j = i + 1; j < convertedArr.length; j++) {
      let pick = [convertedArr[i], convertedArr[j]];
      if (sum - pick[0] - pick[1] === 100) {
        convertedArr.splice(j, 1);
        convertedArr.splice(i, 1);
        isFind = true;
        break;
      }
    }
    if (isFind) {
      break;
    }
  }

  answer = convertedArr.sort((a, b) => a - b).join("\n");
  return answer;
}
/* solve end*/

/* print output */
const output = solution(arr);
console.log(output);
/* print output end*/
