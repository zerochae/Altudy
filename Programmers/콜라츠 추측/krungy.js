/* get input */
const num = 6; // output = 8
// const num = 16; // output = 4
// const num = 626331; // output = -1
/* get input end */

/* solve */
function solution(num) {
  var answer = 0;
  let count = 0;

  if (num === 1) {
    return 0;
  }
  while (count <= 501) {
    num % 2 === 0 ? (num /= 2) : (num = num * 3 + 1);
    if (num === 1) break;
    else count++;
  }
  count <= 500 ? (answer = count + 1) : (answer = -1);
  return answer;
}
/* solve end */

/* print output */
const output = solution(num);
console.log(output);
/* print output end */
