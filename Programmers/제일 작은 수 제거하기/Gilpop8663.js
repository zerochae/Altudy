/* get input */
let arr = [4, 3, 2, 1];
/* get input end */

/* solve */
function solution(arr) {
  var answer = [];
  let min = Number.MAX_SAFE_INTEGER;
  arr.forEach((item) => {
    if (min > item) min = item;
  });
  const findIndex = arr.findIndex((item) => item === min);
  console.log(findIndex);
  answer = [...arr.slice(0, findIndex), ...arr.slice(findIndex + 1)];
  if (answer.length === 0) {
    answer.push(-1);
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(arr));
/* print output end */
