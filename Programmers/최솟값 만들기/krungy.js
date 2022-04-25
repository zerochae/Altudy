/* get input */
const A = [1, 4, 2];
const B = [5, 4, 4]; // output = 29

// const A = [1, 2];
// const B = [3, 4]; // output = 10
/* get input end */

/* solve */
function solution(A, B) {
  var answer = 0;
  A.sort((a, b) => a - b);
  B.sort((a, b) => b - a);

  for (let i = 0; i < A.length; i++) {
    answer += A[i] * B[i];
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(A, B);
console.log(output);
/* print output end */
