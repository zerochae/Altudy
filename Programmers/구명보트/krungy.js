/* get input */
const people = [70, 50, 80, 50];
const limit = 100; // output = 3

// const people = [70, 80, 50];
// const limit = 100; // output = 3
/* get input end */

/* solve */
function solution(people, limit) {
  var answer = 0;
  let lt = 0,
    rt = people.length - 1;
  people.sort((a, b) => b - a);

  while (lt < rt) {
    if (people[lt] + people[rt] > limit) {
      answer++;
      lt++;
    } else {
      lt++;
      rt--;
      answer++;
    }
  }
  if (lt == rt) answer++;
  return answer;
}
/* solve end */

/* print output */
const output = solution(people, limit);
console.log(output);
/* print output end */
