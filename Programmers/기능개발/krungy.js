/* get input */
const progresses = [93, 30, 55];
const speed = [1, 30, 5]; // output = [2, 1]

// const progresses = [95, 90, 99, 99, 80, 99];
// const speed = [1, 1, 1, 1, 1, 1]; // output = [1, 3, 2]

// const progresses = [55, 60, 65];
// const speed = [5, 10, 7]; // output = [3]
/* get input end */

/* solve */
function solution(progresses, speeds) {
  var answer = [];
  let queue = [];
  let day = 0;
  let max = 0;

  if (progresses.length === 1) {
    return [1];
  }

  for (let i = 0; i < progresses.length; i++) {
    queue.push(Math.ceil((100 - progresses[i]) / speeds[i]));
  }

  max = queue[0];
  day++;

  for (let i = 1; i < queue.length; i++) {
    if (max >= queue[i]) {
      day++;
    } else {
      answer.push(day);
      day = 1;
      max = queue[i];
    }
  }
  answer.push(day);
  return answer;
}
/* solve end */

/* print output */
const output = solution(progresses, speed);
console.log(output);
/* print output end */
