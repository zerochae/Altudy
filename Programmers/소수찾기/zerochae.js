const numbers = 17;

const solution = (numbers) => {
  const arr = [];
  const inputs = (numbers + "").split("");
  for (let i = 1; i < inputs.length + 1; i++) {
    arr.push(...getPermutations(inputs, i).map((val) => Number(val.join(""))));
  }
  return [...new Set(arr)].reduce(
    (result, val) => (isPrime(val) ? (result += 1) : result),
    0
  );
};

const getPermutations = (arr, sel) => {
  const results = [];
  if (sel === 1) return arr.map((val) => [val]);

  arr.forEach((fixed, index, origin) => {
    results.push(
      ...getPermutations(
        [...origin.slice(0, index), ...origin.slice(index + 1)],
        sel - 1
      ).map((permutation) => [fixed, ...permutation])
    );
  });

  return results;
};

const isPrime = (num) => {
  for (let i = 2; i < num; i++) {
    if (num % i === 0) return false;
  }
  return num > 1;
};

const output = solution(numbers);

console.log(output);
