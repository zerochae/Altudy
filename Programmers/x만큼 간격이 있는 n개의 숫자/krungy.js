/* get input */
const x = 2;
const n = 5; // output = [2, 4, 6, 8, 10]

// const x = 4;
// const n = 3; // output = [4, 8, 12]

// const x = -4;
// const n = 2; // output = [-4, -8]

// const arr1 = [[1], [2]];
// const arr2 = [[3], [4]]; // output = [[4], [6]]
/* get input end */
/* solve */
function solution(x, n) {
  var answer = [];
  let num = x;

  answer.push(num);
  for (let i = 1; i < n; i++) {
    num += x;
    answer.push(num);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(x, n);
console.log(output);
/* print output end */
