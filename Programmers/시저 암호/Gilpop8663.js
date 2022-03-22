/* get input */
const s = "AB";
let n = 1;
/* get input end */

/* solve */
function solution(s, n) {
  var answer = "";
  for (let i = 0; i < s.length; i++) {
    let strNum = 0;
    if (s[i] === " ") answer += " ";
    else {
      if (s[i].charCodeAt() >= 65 && s[i].charCodeAt() <= 90) {
        if (s[i].charCodeAt() + n > 90) {
          strNum = s[i].charCodeAt() + n - 26;
        } else {
          strNum = s[i].charCodeAt() + n;
        }
      } else {
        if (s[i].charCodeAt() + n > 122) {
          strNum = s[i].charCodeAt() + n - 26;
        } else {
          strNum = s[i].charCodeAt() + n;
        }
      }
      answer += String.fromCharCode(strNum);
    }
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(s, n));
/* print output end */
