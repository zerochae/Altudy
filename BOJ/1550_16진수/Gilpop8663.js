/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `A1A1`;

const input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let answer = 0;
  let num = input;
  let cnt = 0;
  for (let i = num.length - 1; i >= 0; i--) {
    let numbers;
    if (num[i] === "A") {
      numbers = 10;
    } else if (num[i] === "B") {
      numbers = 11;
    } else if (num[i] === "C") {
      numbers = 12;
    } else if (num[i] === "D") {
      numbers = 13;
    } else if (num[i] === "E") {
      numbers = 14;
    } else if (num[i] === "F") {
      numbers = 15;
    } else {
      numbers = +num[i];
    }
    let whereCnt = 16 ** cnt;
    let result = numbers * whereCnt;
    answer += result;
    // console.log(numbers, whereCnt);
    cnt++;
  }
  console.log(answer);

  //   console.log(parseInt(intNum, 16));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
