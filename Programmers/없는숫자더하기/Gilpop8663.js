/* get input */
const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 0];
/* get input end */

/* solve */
function solution(numbers) {
  var answer = -1;
  let sum = 0;
  for (let i = 0; i < numbers.length; i++) {
    sum = sum + numbers[i];
  }
  answer = 45 - sum;
  return answer;
}
/* solve end */

/* print output */
console.log(solution(numbers));
/* print output end */
