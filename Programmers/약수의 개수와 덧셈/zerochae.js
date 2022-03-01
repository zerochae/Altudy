/* get input */
const left = 13;
const right = 17;
/* get input end */

/* solve */
const solution = (left, right) => {
  let index = 0;
  let result = 0;

  while (left + index <= right) {
    const num = left + index;
    result += num * (getDivisor(num) % 2 === 0 ? 1 : -1);
    index++
  }
  return result;
};

const getDivisor = (num) => {
  let index = 1;
  let result = 0;
  while (index <= num) {
    if (num % index === 0) result++;
    index++
  }
  return result;
};
/* solve end */

/* print output */
const output = solution(left, right);
console.log(output);
/* print output end */
