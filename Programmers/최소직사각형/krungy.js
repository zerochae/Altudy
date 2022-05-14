/* get input */
const sizes = [
  [60, 50],
  [30, 70],
  [60, 30],
  [80, 40],
]; // output = 4000
// const sizes = [[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]; // output = 120
// const sizes = [[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]; // output = 133
/* get input end */

/* solve */
function solution(sizes) {
  let arr = sizes.map(([x, y]) => (x < y ? [y, x] : [x, y]));
  let size = [0, 0];

  arr.forEach(([x, y]) => {
    if (x > size[0]) size[0] = x;
    if (y > size[1]) size[1] = y;
  });

  return size[0] * size[1];
}
/* solve end */

/* print output */
const output = solution(sizes);
console.log(output);
/* print output end */
