/* get input */
const n = [1, 2, 3, 4]; // output = 2.5
// const n = [5, 5]; // output = 5.0
/* get input end */

/* solve */
function solution(arr) {
  let sum = 0;
  for (let i = 0; i < arr.length; i++) {
    sum += arr[i];
  }
  return sum / arr.length;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
