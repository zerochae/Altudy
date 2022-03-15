/* get input */
const answers = [1, 2, 3, 4, 5];
/* get input end */

/* solve */

function solution(answers) {
  var answer = [];
  let first = [];
  let second = [];
  let third = [];
  let firstCollect = 0;
  let secondCollect = 0;
  let thirdCollect = 0;

  while (first.length < 10001) {
    first.push(...[1, 2, 3, 4, 5]);
  }
  while (second.length < 10001) {
    second.push(...[2, 1, 2, 3, 2, 4, 2, 5]);
  }
  while (third.length < 10001) {
    third.push(...[3, 3, 1, 1, 2, 2, 4, 4, 5, 5]);
  }
  for (let i = 0; i < answers.length; i++) {
    first.push(1, 2, 3, 4, 5);
  }

  for (let i = 0; i < answers.length; i++) {
    if (first[i] === answers[i]) {
      firstCollect++;
    }
    if (second[i] === answers[i]) {
      secondCollect++;
    }
    if (third[i] === answers[i]) {
      thirdCollect++;
    }
  }
  const max = Math.max(firstCollect, secondCollect, thirdCollect);

  if (max === firstCollect) answer.push(1);
  if (max === secondCollect) answer.push(2);
  if (max === thirdCollect) answer.push(3);

  answer.sort();
  return answer;
}
/* solve end */

/* print output */
console.log(solution(answers));
/* print output end */
