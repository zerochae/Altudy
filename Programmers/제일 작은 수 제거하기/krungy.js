/* get input */
const arr = [4, 3, 2, 1]; // output = [4, 3, 2]
// const arr = [10]; // output = [-1]
/* get input end */

/* solve */
function solution(arr) {
  var answer = [];
  let arrcpy = arr.slice();
  let min = arrcpy.sort((a, b) => b - a).pop();

  for (let i = 0; i < arr.length; i++) {
    arr[i] !== min && answer.push(arr[i]);
  }

  return answer.length ? answer : [-1];
}
/* solve end */

/* print output */
const output = solution(arr);
console.log(output);
/* print output end */
