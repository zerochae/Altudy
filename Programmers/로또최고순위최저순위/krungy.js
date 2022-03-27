/* get input */
const lottos = [44, 1, 0, 0, 31, 25];
const win_nums = [31, 10, 45, 1, 6, 19]; // output = [3, 5]
// const lottos = [0, 0, 0, 0, 0, 0];
// const win_nums = [38, 19, 20, 40, 15, 25]; // output = [1, 6]
// const lottos = [45, 4, 35, 20, 3, 9];
// const win_nums = [20, 9, 3, 45, 4, 35]; // output = [1, 1]
/* get input end */

/* solve */
function solution(lottos, win_nums) {
  var answer = [];
  let max = 0;
  let min = 0;

  for (let i = lottos.length - 1; i >= 0; i--) {
    let eq = win_nums.indexOf(lottos[i]);
    if (eq !== -1) {
      min++;
    }
    if (lottos[i] === 0) {
      max++;
    }
  }

  max += min;
  max = 7 - max;

  if (max === 0) {
    max = 1;
  } else if (max === 7) {
    max = 6;
  }

  min = 7 - min;
  if (min === 0) {
    min = 1;
  } else if (min === 7) {
    min = 6;
  }

  answer.push(lottos, win_nums);

  return answer;
}
/* solve end */

/* print output */
const output = solution(a, b);
console.log(output);
/* print output end */
