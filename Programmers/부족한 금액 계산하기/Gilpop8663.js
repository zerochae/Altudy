/* get input */
const price = 3;
const money = 20;
const count = 4;
/* get input end */

/* solve */
function solution(price, money, count) {
  var answer = -1;
  let sum = 0;
  for (let i = 1; i <= count; i++) {
    sum += price * i;
  }
  if (money - sum < 0) {
    return (answer = Math.abs(money - sum));
  } else {
    return (answer = 0);
  }
}
/* solve end */

/* print output */
console.log(solution(price, money, count));
/* print output end */
