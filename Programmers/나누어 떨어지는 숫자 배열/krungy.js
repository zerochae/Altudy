/* get input */
const arr = [5, 9, 7, 10];
const divisor = 5; // output = [5, 10]

// const arr = [2, 36, 1, 3];
// const divisor = 1; // output = [1, 2, 3, 36]

// const arr = [3, 2, 6];
// const divisor = 10; // output = [-1]
/* get input end */

/* solve */
function solution(arr, divisor) {
  const answer = [];
  arr.map((item) => {
    item % divisor === 0 && answer.push(item);
  });

  return answer.length ? answer.sort((a, b) => a - b) : [-1];
}
/* solve end */

/* print output */
const output = solution(arr, divisor);
console.log(output);
/* print output end */
