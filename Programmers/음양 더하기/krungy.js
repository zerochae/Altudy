/* get input */
const absolutes = [4, 7, 12];
const signs = [true, false, true]; // output = 9

// const absolutes = [1, 2, 3];
// const signs = [false, false, true]; // output = 0
/* get input end */

/* solve */
function solution(absolutes, signs) {
  var answer = 0;

  for (let i = 0; i < absolutes.length; i++) {
    signs[i] === false ? (answer -= absolutes[i]) : (answer += absolutes[i]);
  }

  return answer;
}
/* solve end */

/* print output */
const output = solution(absolutes, signs);
console.log(output);
/* print output end */
