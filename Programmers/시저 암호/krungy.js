/* get input */
const s = "AB";
const n = 1; // output = "BC"
// const s = "z";
// const n = 1 // output = "a"
// const s = "a B z";
// const n = 4 // output = "e F d"
/* get input end */

/* solve */
function solution(s, n) {
  var answer = "";
  let upperStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  let lowerStr = "abcdefghijklmnopqrstuvwxyz";

  let upperArr = upperStr.split("");
  let lowerArr = lowerStr.split("");

  for (let i = 0; i < s.length; i++) {
    if (s[i] === " ") {
      answer += s[i];
      continue;
    }
    if (s[i] >= "a" && s[i] <= "z") {
      let findIndex = (lowerArr.indexOf(s[i]) + n) % 26;
      answer += lowerArr[findIndex];
    } else {
      let findIndex = (upperArr.indexOf(s[i]) + n) % 26;
      answer += upperArr[findIndex];
    }
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(s, n);
console.log(output);
/* print output end */
