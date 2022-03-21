/* get input */
const sizes = [
  [60, 50],
  [30, 70],
  [60, 30],
  [80, 40],
];
/* get input end */

/* solve */
function solution(sizes) {
  var answer = 0;
  let w = Number.MIN_SAFE_INTEGER;
  let h = Number.MIN_SAFE_INTEGER;
  sizes.forEach((item) => item.sort((a, b) => a - b));
  console.log(sizes);
  sizes.forEach((item) => {
    if (w < item[0]) {
      w = item[0];
    }
    if (h < item[1]) {
      h = item[1];
    }
  });
  console.log(w, h);
  answer = w * h;
  return answer;
}
/* solve end */

/* print output */
console.log(solution(sizes));
/* print output end */
