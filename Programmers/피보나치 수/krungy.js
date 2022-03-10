/* get input */
const n = 3; // output = 2
// const n = 5; // output = 5
/* get input end */

/* solve */
function solution(n) {
  // 시간초과 풀이 ...
  // function fibonacci(v) {
  //     if (v < 2) return v
  //     return fibonacci(v - 1) + fibonacci(v - 2)
  // }

  // 왜 안되는지 고민해볼 코드
  // for (let i = 2; i <= n; i++) {
  //   arr[i] = (arr[i - 1] + arr[i - 2]);
  // }

  // return arr[n] % 1234567;

  let arr = [0, 1];

  for (let i = 2; i <= n; i++) {
    arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567;
  }

  return arr[n];
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
