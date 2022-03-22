/* get input */
let n = 2;
let m = 5;
/* get input end */

/* solve */
function solution(n, m) {
  var answer = [];
  let min = n < m ? n : m;
  let max = n < m ? m : n;
  let arr = [];
  for (let i = 1; i <= min; i++) {
    if (min % i === 0 && max % i === 0) {
      arr.push(i);
    }
  }
  answer.push(arr[arr.length - 1]);
  answer.push((max / arr[arr.length - 1]) * min);
  return answer;
}
/* solve end */

/* print output */
console.log(solution(n, m));
/* print output end */
