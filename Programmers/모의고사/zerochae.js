/* get input */
const answers = [5, 4, 4, 2, 1];
// const answers = [1, 3, 2, 4, 2, 1, 4, 4, 4];
/* get input end */

/* set param */
const pattern_A = [1, 2, 3, 4, 5];
const pattern_B = [2, 1, 2, 3, 2, 4, 2, 5];
const pattern_C = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
const result = [0, 0, 0];
/* set param end */

/* solve */
const solution = (answers) => {
  answers.map((answer, index) => {
    if (answer === pattern_A[index % pattern_A.length]) result[0]++;
    if (answer === pattern_B[index % pattern_B.length]) result[1]++;
    if (answer === pattern_C[index % pattern_C.length]) result[2]++;
  });

  const MAX = Math.max(...result);

  return result
    .map((el, index) => {
      return el === MAX ? index + 1 : null;
    })
    .filter((el) => {
      return el !== null;
    });
};
/* solve end */

/* print output */
const output = solution(answers);
console.log(output);
/* print output end */
