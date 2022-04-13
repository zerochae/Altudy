/* get input */
const priorities = [2, 1, 3, 2];
const location = 2; // output = 1

// const priorities = [1, 1, 9, 1, 1, 1];
// const location = 0; // output = 5
/* get input end */

/* solve */
function solution(priorities, location) {
  var answer = 0;
  let stack = [];
  priorities[location] += " ";
  let tmp = Array.from(priorities);

  while (tmp.length >= 1) {
    if (Math.max(...tmp) <= tmp[0]) {
      stack.push(tmp[0]);
      tmp.shift();
    } else {
      tmp.push(tmp[0]);
      tmp.shift();
    }
  }
  for (let i = 0; i < stack.length; i++) {
    if (stack[i].length > 1) {
      answer = i + 1;
      break;
    }
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(priorities, location);
console.log(output);
/* print output end */
