/* get input */
const d = [2, 3, 2, 5, 4, 1, 515, 656156, 84];
const budget = 100000000000;
/* get input end */

/* solve */
function solution(d, budget) {
  var answer = 0;
  let money = budget;
  d.sort((a, b) => a - b).forEach((item) => {
    money = money - item;
    if (money >= 0) {
      answer++;
    }
  });
  return answer;
}
/* solve end */

/* print output */
console.log(solution(d, budget));
/* print output end */
