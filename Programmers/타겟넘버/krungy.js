/* get input */
const numbers = [1, 1, 1, 1, 1];
const target = 3; // output = 5

// const numbers = [4, 1, 2, 1];
// const target = 4; // output = 2
/* get input end */

/* solve */
function solution(numbers, target) {
  let answer = 0;

  function DFS(sum, count) {
    if (count >= numbers.length) {
      if (sum === target) answer++;
      return;
    } else {
      DFS(sum - numbers[count], count + 1);
      DFS(sum + numbers[count], count + 1);
    }
  }

  DFS(0, 0);
  return answer;
}
/* solve end */

/* print output */
const output = solution(num);
console.log(output);
/* print output end */
