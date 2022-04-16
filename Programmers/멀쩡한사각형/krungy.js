/* get input */
const w = 8;
const h = 12; // output = 80
/* get input end */

/* solve */
function gcd(w, h) {
  const max = Math.max(w, h);
  const min = Math.min(w, h);
  const mod = max % min;

  if (mod === 0) return min;
  else return gcd(min, mod);
}

function solution(w, h) {
  let answer;
  const value = gcd(w, h);

  answer = w * h - (w + h - value);
  return answer;
}
/* solve end */

/* print output */
const output = solution(w, h);
console.log(output);
/* print output end */
