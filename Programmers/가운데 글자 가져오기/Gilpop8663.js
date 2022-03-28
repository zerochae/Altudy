/* get input */
const s = "abcde";
/* get input end */

/* solve */
function solution(s) {
  var answer = "";
  if (s.length % 2 === 1) {
    return (answer = s[Math.floor(s.length / 2)]);
  } else {
    return (answer = s[s.length / 2 - 1] + s[s.length / 2]);
  }
}
/* solve end */

/* print output */
console.log(solution(s));
/* print output end */
