/* get input */
let s = "baabaa";
/* get input end */

/* solve */
function solution(s) {
  var answer = -1;
  let arr = [];
  s = s.split("");
  for (let i = 0; i < s.length; i++) {
    if (arr[arr.length - 1] === s[i]) {
      arr.pop();
    } else {
      arr.push(s[i]);
    }
  }
  if (arr.length >= 1) answer = 0;
  else if (arr.length === 0) answer = 1;
  return answer;
}
/* solve end */

/* print output */
console.log(solution(s));
/* print output end */
