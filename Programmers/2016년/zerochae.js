/* get input */
const a = 5;
const b = 24;
/* get input end */

/* solve */
const solution = (a, b) => {
  const week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  return week[new Date(`2016-${a}-${b}`).getDay()];
};
/* solve end */

/* solve */
const solution2 = (a, b) => {
  return new Date(`2016-${a}-${b}`).toDateString().split(" ")[0].toUpperCase();
};
/* solve end */

/* print output */
const output = solution(a, b);
// const output = solution2(a, b);
console.log(output);
/* print output end */
