/* get input */
const left = 13;
const right = 17; // output = 43

// const left = 24;
// const right = 27; // output = 52
/* get input end */

/* solve */
function solution(left, right) {
  var answer = 0;

  for (let i = left; i <= right; i++) {
    let cnt = 0;
    for (let j = 1; j <= i; j++) {
      i % j === 0 && cnt++;
    }
    cnt % 2 === 1 ? (answer -= i) : (answer += i);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(left, right);
console.log(output);
/* print output end */
