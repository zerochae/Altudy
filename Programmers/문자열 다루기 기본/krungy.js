/* get input */
const s = "a234"; // output = false
// const s = 	"1234"; // output = true
/* get input end */

/* solve */
function solution(s) {
  var answer = true;
  let num = "0123456789";

  if (s.length !== 4 && s.length !== 6) return false;
  for (let i = 0; i < s.length; i++) {
    if (num.indexOf(s[i]) === -1) return false;
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
