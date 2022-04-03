/* get input */
const s = "try hello world"; // output = "TrY HeLlO WoRlD"
// const s = "try"; // output = "TrY"
/* get input end */

/* solve */
function solution(s) {
  var answer = "";
  let cnt = 0;

  for (let i = 0; i < s.length; i++) {
    s[i] === " " ? (cnt = 0) : cnt++;

    cnt % 2 === 1 && s[i] !== " "
      ? (answer += s[i].toUpperCase())
      : (answer += s[i].toLowerCase());
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(absolutes, signs);
console.log(output);
/* print output end */
