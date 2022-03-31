/* get input */
let priorities = [1, 1, 9, 1, 1, 1];
let location = 0;
/* get input end */

/* solve */
function solution(priorities, location) {
  var answer = 0;
  let stack = [];
  let newArr = [];
  for (let i = 0; i < priorities.length; i++) {
    newArr.push({ index: i, value: priorities[i] });
  }
  while (newArr.length) {
    if (newArr.length === 1) {
      stack.push(newArr[0]);
      newArr.pop();
      break;
    }
    let max = 0;
    for (let i = 0; i < newArr.length; i++) {
      max = Math.max(max, newArr[i].value);
    }
    if (newArr[0].value === max) {
      stack.push(newArr[0]);
      newArr.shift();
    } else if (newArr[0].value < max) {
      newArr.push(newArr[0]);
      newArr.shift();
    }
  }
  answer = stack.findIndex((item) => item.index === location) + 1;
  return answer;
}
/* solve end */

/* print output */
console.log(solution(priorities, location));
/* print output end */
