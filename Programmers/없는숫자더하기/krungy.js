/* get input */
const numbers = [1, 2, 3, 4, 6, 7, 8, 0]; // output = 14
// const n = [5, 8, 4, 0, 6, 7, 9]; // output = 6
/* get input end */

/* solve */
function solution(numbers) {
  var answer = 0;

  for (let i = 0; i <= 9; i++) {
    if (numbers.indexOf(i) === -1) {
      answer += i;
    }
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(numbers);
console.log(output);
/* print output end */
