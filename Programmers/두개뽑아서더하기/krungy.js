/* get input */
const numbers = [2, 1, 3, 4, 1]; // output = [2, 3, 4, 5, 6, 7]
// const numbers = [5, 0, 2, 7]; // output = [2, 5, 7, 9, 12]

/* get input end */

/* solve */
function solution(numbers) {
  var answer = [];

  for (let i = 0; i < numbers.length - 1; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      if (answer.indexOf(numbers[i] + numbers[j]) === -1) {
        answer.push(numbers[i] + numbers[j]);
      }
    }
  }
  return answer.sort((a, b) => a - b);
}
/* solve end */

/* print output */
const output = solution(numbers);
console.log(output);
/* print output end */
