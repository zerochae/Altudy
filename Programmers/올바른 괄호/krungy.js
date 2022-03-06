/* get input */
const s = "()()"; // output = true
// const s = "(())()"; // output = true
// const s = ")()("; // output = false
// const s = "(()("; // output = false
// const s = "()))((()"; // output = false
// const s = "((((((((((((((((("; // output = false
/* get input end */

/* solve */
function solution(s) {
  var answer = true;
  let stack = [];

  if (s.indexOf(")") === -1) return false;

  for (let i = 0; i < s.length; i++) {
    if (s[i] === "(") stack.push(s[i]);
    else {
      stack.length === 0 ? (answer = false) : stack.pop();
    }
  }

  if (answer === true && stack.length) {
    answer = false;
  }
  return answer;
}

/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
