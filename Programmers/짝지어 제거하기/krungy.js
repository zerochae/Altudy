/* get input */
const s = "baabaa"; // output = 1
// const s = "cdcd"; // output = 0
/* get input end */

/* solve */
function solution(s) {
  let stack = [];

  for (let i = 0; i < s.length; i++) {
    if (!stack.length) {
      stack.push(s[i]);
      continue;
    }
    let tmp = stack[stack.length - 1];
    s[i] === tmp ? stack.pop() : stack.push(s[i]);
  }

  return stack.length ? 0 : 1;
}
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
