/* get input */
const s = "abcde"; // output = "c"
const s = "qwer"; // output = "we"
/* get input end */

/* solve */
function solution(s) {
  return s.length % 2 === 0
    ? s.substr(s.length / 2 - 1, 2)
    : s.substr(Math.floor(s.length / 2), 1);
}
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
