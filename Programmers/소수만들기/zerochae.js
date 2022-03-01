/* get input */
const nums = [1, 2, 3, 4];
/* get input end */

/* solve */
const solution = (nums) => {
  const combinations = getCombinations(nums, 3);

  return combinations.reduce(
    (result, combination) =>
      (result += isPrime(combination.reduce((acc, cur) => acc + cur, 0))
        ? 1
        : 0),
    0
  );
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

const isPrime = (num) => {
  if (num === 2) return true;

  for (let i = 2; i <= Math.floor(Math.sqrt(num)); i++) {
    if (num % i === 0) return false;
  }
  return true;
};
/* solve end */

/* print output */
const output = solution(nums);
console.log(output);
/* print output end */
