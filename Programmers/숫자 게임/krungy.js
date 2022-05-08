/* get input */
const A = [5, 1, 3, 7];
const B = [2, 2, 6, 8]; // output = 3

// const A = [2, 2, 2, 2];
// const B = [1, 1, 1, 1]; // output = 0
/* get input end */

/* solve */
function solution(A, B) {
  var answer = 0;
  A.sort((a, b) => b - a);
  B.sort((a, b) => a - b);

  for (let i = 0; i < A.length; i++) {
    if (A[i] < B[B.length - 1]) {
      B.pop();
      answer++;
    }
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(A, B);
console.log(output);
/* print output end */
