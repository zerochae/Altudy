/* get input */
const price = 3;
const money = 20;
const count = 4; // output = 10
/* get input end */

/* solve */
function solution(price, money, count) {
  var answer = -1;
  let needMoney = 0;
  for (let i = 1; i <= count; i++) {
    needMoney += price * i;
  }
  needMoney > money ? (answer = needMoney - money) : (answer = 0);

  return answer;
}
/* solve end */

/* print output */
const output = solution(price, money, count);
console.log(output);
/* print output end */
