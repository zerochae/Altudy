/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
const filePath = `2184545 95654635`;

const input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let A = input.split(" ")[0];
  let B = input.split(" ")[1];
  let leastCommonMeasure,
    greatestCommonMeasure = Number.MIN_SAFE_INTEGER;
  let minNum = Math.min(A, B);
  let maxNum = Math.max(A, B);
  for (let i = 1; i <= minNum; i++) {
    if (A % i === 0 && B % i === 0) {
      greatestCommonMeasure = Math.max(greatestCommonMeasure, i);
    }
  }
  let aIndex = 1,
    bIndex = 1;
  while (A * aIndex === B * bIndex ? false : true) {
    let numA = A * aIndex;
    let numB = B * bIndex;

    if (numA > numB) {
      bIndex++;
    } else if (numA < numB) {
      aIndex++;
    }
  }
  leastCommonMeasure = A * aIndex;
  console.log(greatestCommonMeasure);
  console.log(leastCommonMeasure);
};

// };
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
