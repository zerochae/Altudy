/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `4 11
// 802
// 743
// 457
// 539`;

const input = filePath.toString().trim().split("\n");
/* get input end */
// 6 5
// 5 4
/* set param */

/* set param end */

/* solve */
const solution2 = (input) => {
  let answer = 0;
  let count = +input[0].split(" ")[0];
  let requiredCount = +input[0].split(" ")[1];
  input = input.slice(1).map((item) => +item);
  let maxNum = Number.MIN_SAFE_INTEGER;
  const sum = input.reduce((sum, item) => {
    maxNum = Math.max(maxNum, item);
    return sum + item;
  }, 0);
  let high = Math.floor(sum / requiredCount);
  let low = 0;
  let mid;
  let maxMid = Number.MIN_SAFE_INTEGER;
  while (answer === requiredCount ? false : true) {
    answer = 0;
    mid = Math.floor((high + low) / 2);
    for (let i = 0; i < count; i++) {
      answer += Math.floor(input[i] / mid);
    }
    if (answer < requiredCount) {
      high = mid - 1;
    } else if (answer > requiredCount) {
      low = mid + 1;
      // console.log(answer, mid, high);
    }
  }
  // console.log(answer, mid, high, low, maxNum);
  while (answer !== requiredCount ? false : true) {
    answer = 0;
    mid = Math.floor((high + low) / 2);
    for (let i = 0; i < count; i++) {
      answer += Math.floor(input[i] / mid);
    }
    if (answer === requiredCount) {
      low = mid + 1;
      maxMid = Math.max(maxMid, mid);
    }
  }
  // console.log(answer);
  answer = 0;
  while (answer === requiredCount - 1 ? false : true) {
    answer = 0;
    for (let i = 0; i < count; i++) {
      answer += Math.floor(input[i] / maxMid);
    }
    if (answer !== requiredCount - 1) {
      maxMid++;
    }
  }
  // console.log(answer, mid, high, low, maxMid);
  console.log(maxMid - 1);
  // console.log(sum / mid);
};
// const solution = (input) => {
//   let count = +input[0].split(" ")[0];
//   let requiredCount = +input[0].split(" ")[1];
//   //   console.log(count, requiredCount);
//   input = input.slice(1).map((item) => +item);
//   //   console.log(input);
//   let maxNum = Number.MIN_SAFE_INTEGER;
//   const sum = input.reduce((sum, item) => {
//     maxNum = Math.max(maxNum, item);
//     return sum + item;
//   }, 0);
//   let divide = Math.floor(sum / requiredCount);
//   if (divide > maxNum) {
//     divide = maxNum;
//   }
//   let answer = 0;
//   let conditional = 0;

//   //   console.log(sum / requiredCount, maxNum);
//   for (let i = 0; i < count; i++) {
//     answer += Math.floor(input[i] / divide);
//   }
//   while (answer < requiredCount) {
//     answer = 0;
//     for (let i = 0; i < count; i++) {
//       answer += Math.floor(input[i] / divide);
//     }
//     divide--;
//     if (answer === requiredCount) break;
//     // cnt++;
//     // console.log(cnt);
//   }
//   //   console.log(answer, divide);
//   console.log(divide + 1);
// };
/* solve end */

/* print output */
// const output1 = solution(input);
const output = solution2(input);
// console.log(output);
/* print output end */
