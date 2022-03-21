/* get input */
const a = 5;
const b = 24;
/* get input end */

/* solve */
function solution(a, b) {
  var answer = "";
  const days = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  const date = new Date(2016, a - 1, b, 0).getDay();
  answer = days[date];
  return answer;
}
/* solve end */

/* print output */
console.log(solution(a, b));
/* print output end */
