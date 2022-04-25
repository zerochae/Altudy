/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `1
// 1 1
// 0`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const kN = +input[0];
  const [m, n] = input[1].split(" ").map((item) => +item);
  let dist = Array.from({ length: 32 }, () =>
    Array.from({ length: 202 }, () => Array.from({ length: 202 }))
  );
  let board = [];
  for (let i = 2; i < input.length; i++) {
    board.push(input[i].split(" "));
  }

  let dx = [1, 0, -1, 0];
  let dy = [0, 1, 0, -1];

  let dkx = [-2, -2, -1, -1, 1, 1, 2, 2];
  let dky = [1, -1, 2, -2, 2, -2, 1, -1];

  let queue = [];
  let head = 0;
  let tail = 0;

  dist[0][0][0] = 1;
  queue.push([0, 0, 0]);
  tail++;

  while (head < tail) {
    const [k, x, y] = queue[head++];

    if (k < kN) {
      for (let i = 0; i < 8; i++) {
        let nx = x + dkx[i];
        let ny = y + dky[i];
        if (nx < 0 || ny < 0 || ny >= m || nx >= n) continue;
        if (board[nx][ny] === "1") continue;
        if (dist[k + 1][nx][ny] > 0) continue;
        dist[k + 1][nx][ny] = dist[k][x][y] + 1;
        queue.push([k + 1, nx, ny]);
        tail++;
      }
    }

    for (let i = 0; i < 4; i++) {
      let nx = x + dx[i];
      let ny = y + dy[i];
      if (nx < 0 || ny < 0 || ny >= m || nx >= n) continue;
      if (board[nx][ny] === "1") continue;
      if (dist[k][nx][ny] > 0) continue;
      dist[k][nx][ny] = dist[k][x][y] + 1;
      queue.push([k, nx, ny]);
      tail++;
    }
    // console.log(queue);
  }
  let answer = Number.MAX_SAFE_INTEGER;
  for (let i = 0; i <= kN; i++) {
    // console.log(dist[i][n - 1][m - 1]);
    if (dist[i][n - 1][m - 1]) {
      answer = Math.min(answer, dist[i][n - 1][m - 1] - 1);
    }
  }
  if (answer === Number.MAX_SAFE_INTEGER) {
    answer = -1;
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
