/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `5 4
// ####
// #...
// #.##
// #.J#
// ####`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  // console.log(input);
  let answer;
  input[0] = input[0].split(" ");
  const n = +input[0][0];
  const m = +input[0][1];
  let room = [];
  let queue = [];
  let fire = [];
  let dist = Array.from({ length: n }, () => Array.from({ length: m }));
  // console.log(dist);
  const dx = [1, 0, -1, 0];
  const dy = [0, 1, 0, -1];
  for (let i = 1; i < input.length; i++) {
    room.push(input[i].split(""));
  }
  // console.log(room);
  let head = 0;
  let tail = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (room[i][j] === "J") {
        queue.push([i, j]);
        dist[i][j] = 0;
      } else if (room[i][j] === "F") {
        fire.push([i, j]);
        dist[i][j] = 0;
        tail++;
      }
    }
  }
  while (head < tail) {
    const [x, y] = fire[head];
    head++;
    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (dist[nx][ny] >= 0 || room[nx][ny] !== ".") continue;
      dist[nx][ny] = dist[x][y] + 1;
      fire.push([nx, ny]);
      tail++;
    }
  }
  // console.log(tail);
  head = 0;
  tail = 1;
  while (head < tail) {
    const [x, y] = queue[head];
    head++;

    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        return console.log(dist[x][y] + 1);
      }
      if (dist[nx][ny] <= dist[x][y] + 1 || room[nx][ny] !== ".") continue;
      dist[nx][ny] = dist[x][y] + 1;
      queue.push([nx, ny]);
      tail++;
    }
  }

  // console.log(dist, max, wallX, wallY);
  // console.log(dist);
  // console.log(tail);
  answer = "IMPOSSIBLE";
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
