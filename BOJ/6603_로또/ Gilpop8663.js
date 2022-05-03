/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
const filePath = `7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";
  let answer = "";
  for (let i = 0; i < input.length - 1; i++) {
    input[i] = input[i].split(" ");
    const n = +input[i][0];
    let arr = [];
    let ans = Array.from({ length: 6 }, () => 0);
    let isused = Array.from({ length: 6 }, () => 0);
    let tmp = 0;

    for (let j = 1; j <= n; j++) {
      //   console.log(input[i][j]);
      arr.push(+input[i][j]);
    }
    // console.log(arr);
    function func(k) {
      //   console.log(n, arr);
      //   console.log(k, n);
      if (k === n) {
        // console.log(ans);
        answer += ans.slice().join(" ") + "\n";
        // console.log(arr);
        return;
      } else {
        for (let i = 0; i < 6; i++) {
          if (isused[i] === 0 && tmp < arr[i]) {
            ans[k] = arr[i];
            tmp = ans[k];
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
          }
        }
      }
    }
    // console.log(ans);
    func(0);

    console.log(answer);
  }

  //   console.log(input);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
