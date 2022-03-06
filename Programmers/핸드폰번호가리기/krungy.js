/* get input */
const phone_number = "01033334444"; // output = "*******4444"
// const phone_number = "027778888"; // output = "*****8888"
/* get input end */

/* solve */
function solution(phone_number) {
  let answer = "";

  for (let i = 0; i < phone_number.length; i++) {
    i < phone_number.length - 4 ? (answer += "*") : (answer += phone_number[i]);
  }

  return answer;
}
/* solve end */

/* print output */
const output = solution(phone_number);
console.log(output);
/* print output end */
