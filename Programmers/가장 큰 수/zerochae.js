const numbers = [6, 10, 2];

/* solve */
const solution = (numbers) => {

  const result = numbers
  .sort((a, b) => {
    a = String(a);
    b = String(b);
    return Number(b + a) - Number(a + b);
  })
  .join("");

  return Number(result) === 0 ? '0' : result;
};
/* solve end */

const output = solution(numbers);
console.log(output);
