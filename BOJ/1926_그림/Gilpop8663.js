/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `6 5
// 1 1 0 1 1
// 0 1 1 0 0
// 0 0 0 0 0
// 1 0 1 1 1
// 0 0 1 1 1
// 0 0 1 1 1`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  // console.log(input);
  input[0] = input[0].split(" ").map((item) => +item);
  const n = input[0][0]; //행
  const m = input[0][1]; // 열
  let strAnswer = "";
  let answer = 0;
  const dx = [1, 0, -1, 0];
  const dy = [0, 1, 0, -1];
  let queue = [];
  let arr = [];
  for (let i = 1; i <= n; i++) {
    input[i] = input[i].split(" ").map((item) => +item);
    arr.push(input[i]);
  }
  // console.log(arr);
  let maxNum = Number.MIN_SAFE_INTEGER;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      let tmp = 0;
      // console.log(arr[i][j]);
      if (arr[i][j] === 1) {
        arr[i][j] = 0;
        queue.push([i, j]);
        answer++;
        tmp++;
      }
      while (queue.length) {
        let [x, y] = queue.shift();
        for (let k = 0; k < 4; k++) {
          let nx = x + dx[k];
          let ny = y + dy[k];
          if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] === 1) {
            arr[nx][ny] = 0;
            queue.push([nx, ny]);
            tmp++;
          }
        }
      }
      maxNum = Math.max(maxNum, tmp);
    }
  }
  // console.log(answer, arr, maxNum);
  strAnswer = answer + "\n" + maxNum;
  console.log(strAnswer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
