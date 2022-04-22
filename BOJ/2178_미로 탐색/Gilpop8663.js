/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
const filePath = `4 6
101111
101010
101011
111011`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  input[0] = input[0].split(" ");

  const n = +input[0][0];
  const m = +input[0][1];
  let dx = [1, 0, -1, 0];
  let dy = [0, 1, 0, -1];
  let board = [];
  let queue = [];
  let dist = Array.from({ length: n }, () => Array.from({ length: m }));
  for (let i = 1; i < input.length; i++) {
    board.push(input[i].split("").map((item) => +item));
  }
  dist[0][0] = 0;
  queue.push([0, 0]);

  while (queue.length) {
    let [x, y] = queue.shift();
    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];
      if (
        nx >= 0 &&
        nx < n &&
        ny >= 0 &&
        ny < m &&
        board[nx][ny] === 1 &&
        !dist[nx][ny]
      ) {
        dist[nx][ny] = dist[x][y] + 1;
        queue.push([nx, ny]);
        // console.log(queue);
      }
    }
  }
  console.log(dist[n - 1][m - 1] + 1);
};
// const solution = (input) => {
//   "use strict";
//   console.log(input);
//   input[0] = input[0].split(" ");

//   const n = +input[0][0];
//   const m = +input[0][1];
//   let dx = [1, 0, -1, 0];
//   let dy = [0, 1, 0, -1];
//   let board = [];
//   let queue = [];
//   let dist = Array.from({ length: n }, () => Array.from({ length: m }));
//   for (let i = 1; i < input.length; i++) {
//     board.push(input[i].split("").map((item) => +item));
//   }
//   dist[0][0] = 0;
//   queue.push([0, 0]);

//   while (queue.length) {
//     let [x, y] = queue.shift();
//     // console.log(queue, board[x][y]);
//     for (let k = 0; k < 4; k++) {
//       let nx = x + dx[k];
//       let ny = y + dy[k];
//       if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//       if (dist[nx][ny] >= 0 || board[nx][ny] !== 1) continue;
//       dist[nx][ny] = dist[x][y] + 1;
//       queue.push([nx, ny]);
//       console.log(queue);
//     }
//   }
//   console.log(dist[n - 1][m - 1] + 1);
// };
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
