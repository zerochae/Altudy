/* get input */
const n = 3; // output = "수박수"
// const n = 4; // output = "수박수박"
/* get input end */

/* solve */
function solution(n) {
  var answer = "";
  let i = 0;
  while (i < n) {
    i % 2 === 0 ? (answer += "수") : (answer += "박");
    i++;
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
