/* get input */
const seoul = ["Jane", "Kim"]; // output = "김서방은 1에 있다"
/* get input end */

/* solve */
function solution(seoul) {
  let indexKim = seoul.indexOf("Kim");
  let answer = `김서방은 ${indexKim}에 있다`;
  return answer;
}
/* solve end */

/* print output */
const output = solution(seoul);
console.log(output);
/* print output end */
