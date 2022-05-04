/* get input */
const number = "1924";
const k = 2; // output = "94"

// const number = "1231234";
// const k = 2; // output = "94"

// const number = "4177252841";
// const k = 4; // output = "775841"
/* get input end */

/* solve */
function solution(number, k) {
  var answer = "";
  let stack = [];

  for (let i = 0; i < number.length; i++) {
    const num = number[i];

    while (k > 0 && stack[stack.length - 1] < num) {
      stack.pop();
      k--;
    }
    stack.push(num);
  }
  stack.splice(stack.length - k, k);
  answer = stack.join("");

  return answer;
}
/* solve end */

/* print output */
const output = solution(number, k);
console.log(output);
/* print output end */
