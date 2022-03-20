/* get input */
const left = 24;
const right = 27;
/* get input end */

/* solve */
function solution(left, right) {
  var answer = 0;
  let leftNum = left;
  while (leftNum < right + 1) {
    let count = 0;
    for (let i = 1; i <= leftNum; i++) {
      if (leftNum % i === 0) {
        count++;
      }
    }
    if (count % 2 === 1) answer -= leftNum;
    else if (count % 2 === 0) answer += leftNum;
    console.log(count);
    leftNum++;
  }

  return answer;
}
/* solve end */

/* print output */
console.log(solution(left, right));
/* print output end */
