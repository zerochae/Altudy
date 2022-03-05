/* get input */
const absolutes = [4, 7, 12];
const signs = [true, false, true];
/* get input end */

/* solve */
function solution(absolutes, signs) {
  var answer = 123456789;
  let sum = 0;
  for (let i = 0; i < signs.length; i++) {
    if (signs[i]) sum += absolutes[i];
    else sum -= absolutes[i];
  }
  answer = sum;
  return answer;
}
/* solve end */

/* print output */
const output = solution(absolutes, signs);
console.log(output);
/* print output end */
