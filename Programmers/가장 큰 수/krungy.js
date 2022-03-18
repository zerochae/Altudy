/* get input */
const numbers = [6, 10, 2]; // output = "6210"
// const numbers = [3, 30, 34, 5, 9]; // output = "9534330"
/* get input end */

/* solve */
function solution(numbers) {
  const answer = numbers.map((num) => num + "").sort((a, b) => b + a - (a + b));

  return answer[0] === "0" ? "0" : answer.join("");
}
/* solve end*/

/* print output */
const output = solution(numbers);
console.log(output);
/* print output end*/
