/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `4 4 3
// 0111
// 1111
// 1111
// 1110`;

let input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";
  let [n, m, k] = input[0].split(" ").map((item) => +item);
  // console.log(n, m, k);
  let board = [];
  // let dist = Array.from({ length: 1002 }, () =>
  //   Array.from({ length: 1002 }, () => Array.from({ length: 12 }))
  // );
  // let dist = Array(1002).fill(Array(1002).fill(Array(12).fill(0)));
  let dist = Array.from({ length: 1002 }, () =>
    Array.from({ length: 1002 }, () => Array.from({ length: 12 }))
  );
  // console.log(dist);
  for (let i = 1; i < input.length; i++) {
    board.push(input[i].split(""));
  }
  let dx = [1, 0, -1, 0];
  let dy = [0, 1, 0, -1];
  let queue = [];
  let head = 0;
  let tail = 0;
  queue.push([0, 0, 0]);
  dist[0][0][0] = 1;
  tail++;

  while (head < tail) {
    const [x, y, w] = queue[head++];
    // console.log(dist[x][y][w]);
    if (x === n - 1 && y === m - 1) {
      // console.log(queue);
      return console.log(dist[x][y][w]);
    }
    for (let dir = 0; dir < 4; dir++) {
      let nx = x + dx[dir];
      let ny = y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      let nw = w;
      if (board[nx][ny] === "1") nw++;
      // console.log(dist[nx][ny][nw]);
      if (nw > k || dist[nx][ny][nw] > 0) continue;
      // console.log(nx, ny, nw, dist[nx][ny][nw]);
      dist[nx][ny][nw] = dist[x][y][w] + 1;
      queue.push([nx, ny, nw]);
      tail++;
    }
  }
  // console.log(board);
  console.log(-1);
  // console.log(queue);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
