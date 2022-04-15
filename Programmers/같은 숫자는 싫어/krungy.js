/* get input */
const arr = [1, 1, 3, 3, 0, 1, 1]; // output = [1, 3, 0, 1]
// const arr = [4, 4, 4, 3, 3]; // output = [4, 3]
/* get input end */
/* solve */
function solution(arr) {
  var answer = [];
  for (let i = 0; i < arr.length; i++) {
    answer[answer.length - 1] !== arr[i] && answer.push(arr[i]);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(arr);
console.log(output);
/* print output end */
