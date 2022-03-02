/* get input */
const sizes = [
  [60, 50],
  [30, 70],
  [60, 30],
  [80, 40],
];
/* get input end */

/* solve */
const solution = (sizes) => {

  let w = 0;
  let h = 0;

  sizes.map((size) => {
    size.sort((a, b) => a - b);
    w = Math.max(w, size[0]);
    h = Math.max(h, size[1]);
  });

  return w * h;
};
/* solve end */

/* print output */
const output = solution(sizes);
console.log(output);
/* print output end */
