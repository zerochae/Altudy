/* get input */
const s = "3people unFollowed me"; // output = '3people Unfollowed Me'
// const s = "for the last week"; // output = 'For The Last Week'
// const s = "for     the      "; // output = 'For     The      '
/* get input end */

/* solve */
function solution(s) {
  let answer = "";
  let isFirst = true;

  for (let i = 0; i < s.length; i++) {
    isFirst ? (answer += s[i].toUpperCase()) : (answer += s[i].toLowerCase());
    s[i] === " " ? (isFirst = true) : (isFirst = false);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
