/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
const filePath = `5 20
4 42 40 26 46`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  const trees = +input[0].split(" ")[0];
  const treeNeed = +input[0].split(" ")[1];
  input = input[1].split(" ").map((item) => +item);
  //   console.log(trees, treeNeed, input);
  let maxNum = Number.MIN_SAFE_INTEGER;
  input.forEach((item) => {
    maxNum = Math.max(item, maxNum);
  });
  let answer = 0;

  let high = maxNum;
  let low = 0;
  let mid;
  //   console.log(low, high);
  while (low <= high) {
    answer = 0;
    mid = parseInt((high + low) / 2);
    // console.log(mid);
    for (let i = 0; i < trees; i++) {
      //   console.log(input[i]);
      if (input[i] - mid > 0) {
        answer += input[i] - mid;
      }
    }
    if (answer < treeNeed) {
      high = mid - 1;
    } else low = mid + 1;
  }
  //   console.log(answer, high);
  console.log(high);
  //   console.log(answer, mid);
};

// };
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
