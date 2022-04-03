/* get input */
const numbers = [1, 3, 2, 5, 4];
const budget = 9; // output = 3

// const numbers = [2, 2, 3, 3];
// const budget = 10; // output = 4
/* get input end */

/* solve */
function solution(d, budget) {
  var answer = 0;
  d.sort((a, b) => a - b);
  let i = 0;

  while (true) {
    if (budget >= d[i]) {
      budget -= d[i];
      i++;
    } else break;
  }

  answer = i;

  return answer;
}
/* solve end */

/* print output */
const output = solution(numbers);
console.log(output);
/* print output end */
