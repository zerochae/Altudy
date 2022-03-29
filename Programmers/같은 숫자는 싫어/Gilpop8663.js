/* get input */
const arr = [4, 4, 4, 3, 3];
/* get input end */

/* solve */
function solution(arr) {
  var answer = [];

  arr.forEach((item, i) => {
    if (item === arr[i + 1]) return;
    else answer.push(item);
  });
  return answer;
}
/* solve end */

/* print output */
console.log(solution(arr));
/* print output end */
