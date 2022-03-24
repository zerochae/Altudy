/* get input */
const progresses = [55, 60, 65];
const speeds = [5, 10, 7];
/* get input end */

/* solve */
function solution(progresses, speeds) {
  var answer = [];
  let day = 0;
  let index = 0;
  let count = 0;
  let copyArr = [...progresses];

  while (copyArr[index] < 100 && index < progresses.length) {
    count = 0;
    day++;
    copyArr[index] = progresses[index] + speeds[index] * day;
    if (copyArr[index] >= 100) {
      index++;
      count++;
      while (progresses[index] + speeds[index] * day >= 100) {
        copyArr[index] = progresses[index] + speeds[index] * day;
        index++;
        count++;
      }
    }
    if (count > 0) {
      answer.push(count);
    }
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(progresses, speeds));
/* print output end */
