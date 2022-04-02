/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `3
// 2 2
// 1 5
// 13 29`;

const input = filePath
  .toString()
  .trim()
  .split("\n")
  .map((item) => item.trim());
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  //   console.log(input);
  let n = input[0];

  for (let i = 1; i <= input.length - 1; i++) {
    let dy = Array.from(Array(35), () => Array(35).fill(0));
    const set = new Set();
    let west = +input[i].split(" ")[0];
    let east = +input[i].split(" ")[1];
    // console.log(west, east);
    let westArr = Array.from(Array(west), (x, i) => i);
    let eastArr = Array.from(Array(east), (x, i) => i);
    // console.log(westArr, eastArr);
    let maxNum = Math.max(west, east);
    let minNum = Math.min(west, east);
    function DFS(n, r) {
      if (dy[n][r] > 0) return dy[n][r];
      if (r === 0 || n === r) return 1;
      else {
        return (dy[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r));
      }
    }
    let result = DFS(maxNum, minNum);
    console.log(result);
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
