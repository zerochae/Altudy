/* get input */
const s = "1 2 3 4"; // output = "1 4"
// const s = "-1 -2 -3 -4"; // output =	"-4 -1"
// const s = "-1 -1"; // output =	"-1 -1"
/* get input end */

/* solve */
function solution(s) {
  let sCpy = s.slice().split(" ");
  let max = sCpy[0] * 1;
  let min = sCpy[0] * 1;
  for (let i = 0; i < sCpy.length; i++) {
    let tmp = sCpy[i] * 1;

    if (tmp > max) max = tmp;
    if (tmp < min) min = tmp;
  }
  return `${min} ${max}`;
}
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
