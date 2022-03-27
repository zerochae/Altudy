/* get input */
const numbers = [4, 1, 2, 1];
const target = 4;
/* get input end */

/* solve */
function solution(numbers, target) {
  var answer = 0;

  function DFS(L, s, sum) {
    if (L === numbers.length) {
      if (sum === target) {
        answer++;
      }
    } else {
      DFS(L + 1, s + 1, sum + numbers[L]);
      DFS(L + 1, s + 1, sum - numbers[L]);
    }
  }
  DFS(0, 0, 0);

  return answer;
}
/* solve end */

/* print output */
console.log(solution(numbers, target));
/* print output end */
