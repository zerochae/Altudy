/* get input */
const a = 5;
const b = 24; // output = "TUE"
/* get input end */

/* solve */
function solution(a, b) {
  const week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  const date = new Date(`2016-${a}-${b}`);

  return week[date.getDay()];
}
/* solve end */

/* print output */
const output = solution(a, b);
console.log(output);
/* print output end */
