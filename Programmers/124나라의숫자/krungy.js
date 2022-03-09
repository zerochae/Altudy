/* get input */
const n = 1; // output = "1"
// const n = 2; // output = "2"
// const n = 3; // output = "4"
// const n = 4; // output = "11"
// const n = 8; // output = "22"
// const n = 7; // output = "21"
// const n = 6; // output = "14"
// const n = 5; // output = "12"
/* get input end */

/* solve */
function solution(n) {
  let answer = "";
  const arr = [4, 1, 2];

  while (n) {
    answer = arr[n % 3] + answer;

    n % 3 === 0 ? (n = Math.floor(n / 3) - 1) : (n = Math.floor(n / 3));
  }

  return answer;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
