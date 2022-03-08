/* get input */
const numbers = [2, 1, 3, 4, 1];
/* get input end */

/* set param */
const result = [];
/* set param end */

/* solve */
const solution = (numbers) => {
  return [...new Set(
    getCombinations(numbers, 2).map((arr) => {
      return arr.reduce((acc, cur) => acc + cur, 0);
    })
  )].sort((a, b) => a - b);
};

const getCombinations = (arr, selectNum) => {
  const results = [];
  if (selectNum === 1) return arr.map((val) => [val]);
  arr.forEach((fixed, index, origin) => {
    results.push(
      ...getCombinations(origin.slice(index + 1), selectNum - 1).map(
        (combination) => [fixed, ...combination]
      )
    );
  });
  return results;
};
/* solve end */

/* print output */
const output = solution(numbers);
console.log(output);
/* print output end */
