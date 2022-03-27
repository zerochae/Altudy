/* get input */
let phone_number = "01033334444";
/* get input end */

/* solve */
function solution(phone_number) {
  var answer = "";
  phone_number.split("").forEach((item, i) => {
    if (phone_number.length - i < 5) {
      answer += item;
    } else {
      answer += "*";
    }
  });
  return answer;
}
/* solve end */

/* print output */
console.log(solution(phone_number));
/* print output end */
