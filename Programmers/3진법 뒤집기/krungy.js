/* get input */
const n = 45; // output = 7
// const n = 125; // output = 229
// const n = 78413450; // output = 110105530
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  let converted = n.toString(3);
  let reversed = "";

  for (let i = converted.length - 1; i >= 0; i--) {
    reversed += converted[i];
  }

  answer = parseInt(reversed, 3);
  return answer;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
