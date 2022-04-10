/* get input */
const n = 3;
const m = 12; // output = [3, 12]

// const n = 2;
// const m = 5; // output = [1, 10]
/* get input end */

/* solve */
function solution(n, m) {
  const greatest = (a, b) => {
    if (b === 0) return a;
    return greatest(b, a % b);
  };

  const least = (a, b) => (a * b) / greatest(a, b);

  return [greatest(n, m), least(n, m)];
}
/* solve end */

/* print output */
const output = solution(n, m);
console.log(output);
/* print output end */
