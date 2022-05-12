/* get input */
const n = 10; // output = 4
// const n = 5; // output = 3
/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  let arr = [];

  for (let i = 2; i <= n; i++) {
    arr[i] = 1;
  }
  for (let i = 2; i <= n; i++) {
    if (arr[i] == 0) continue;
    for (let j = i + i; j <= n; j += i) {
      arr[j] = 0;
    }
  }
  for (let i = 2; i <= n; i++) {
    if (arr[i] == 1) answer++;
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
