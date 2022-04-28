/* get input */
const arr = [2, 6, 8, 14]; // output = 168
// const arr = [1, 2, 3]; // output = 6
/* get input end */

/* solve */
const gdc = (a, b) => {
  while (b > 0) {
    let tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
};

const lcm = (a, b) => {
  return (a * b) / gdc(a, b);
};

function solution(arr) {
  var answer = 1;

  for (let i = 0; i < arr.length; i++) {
    answer = lcm(answer, arr[i]);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(arr);
console.log(output);
/* print output end */
