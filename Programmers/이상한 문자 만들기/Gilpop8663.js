/* get input */
let s = "  try  hello world";
/* get input end */

/* solve */
function solution(s) {
  var answer = "";
  let count = 0;
  for (let i = 0; i < s.length; i++) {
    if (s[i] === " ") {
      answer += " ";
      count = 0;
    } else if (count % 2 === 0) {
      answer += s[i].toUpperCase();
      count++;
    } else if (count % 2 === 1) {
      answer += s[i].toLowerCase();
      count++;
    }
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(s));
/* print output end */
