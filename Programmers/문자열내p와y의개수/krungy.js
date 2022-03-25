/* get input */
const s = "pPoooyY"; // output = true
// const s = "Pyy"; // output = false
/* get input end */

/* solve */
function solution(s) {
  var answer = true;
  let pCnt = 0;
  let yCnt = 0;
  for (let i = 0; i < s.length; i++) {
    if (s[i] === "p" || s[i] === "P") pCnt++;
    if (s[i] === "y" || s[i] === "Y") yCnt++;
  }
  if (pCnt !== yCnt) answer = false;
  return answer;
}
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
