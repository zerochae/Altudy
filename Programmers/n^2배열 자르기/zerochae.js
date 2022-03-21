const n = 3;
const left = 2;
const right = 5;

const solution = (n, left, right) =>
  new Array(right - left + 1).fill(null).reduce(
    (result) => {
      result.arr.push(
        Math.max(Math.floor(result.index / n) + 1, (result.index++ % n) + 1)
      );
      return result;
    },
    {
      arr: [],
      index: left,
    }
  ).arr;

const output = solution(n, left, right);

console.log(output);
