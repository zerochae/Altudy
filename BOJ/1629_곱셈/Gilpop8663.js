/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `2 6 10`;

const input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */

const POW = (a, b, m) => {
  if (b === 1n) return a % m;
  let val = POW(a, BigInt(parseInt(b / 2n)), m);
  val = (val * val) % m;
  if (b % 2n === 0n) return val;
  return (val * a) % m;
};

const solution = (input) => {
  const [A, B, C] = input.map((item) => BigInt(item));
  console.log(Number(POW(A, B, C)));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
