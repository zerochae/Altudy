/* get input */
const answers = [5, 4, 4, 2, 1];
// const answers = [1, 3, 2, 4, 2, 1, 4, 4, 4];
/* get input end */

/* set param */
const patterns = [
  [1, 2, 3, 4, 5],
  [2, 1, 2, 3, 2, 4, 2, 5],
  [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
];
const result = [0, 0, 0];
/* set param end */

/* solve */
const solution = (answers) => {
  answers.map((answer, ans_Idx) => {
    patterns.map((pattern, pat_Idx) => {
      answer === pattern[ans_Idx % pattern.length] ? result[pat_Idx]++ : null;
    });
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
