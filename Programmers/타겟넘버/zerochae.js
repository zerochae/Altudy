const numbers = [1, 1, 1, 1, 1];
const target = 3;

/**
 *
 * @param {number[]} numbers
 * @param {number} target
 */
const solution = (numbers, target) => {
  let result = 0;
  const dfs = (depth, sum) => {
    if (depth === numbers.length) {
      if (sum === target) result++;
      return;
    }
    dfs(depth + 1, sum + numbers[depth]);
    dfs(depth + 1, sum - numbers[depth]);
  };
  dfs(0, 0);

  return result;
};

const output = solution(numbers, target);

console.log(output);
