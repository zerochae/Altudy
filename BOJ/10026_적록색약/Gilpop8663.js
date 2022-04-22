/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `5
// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const n = +input[0];

  let color = [];

  for (let i = 1; i < input.length; i++) {
    color.push(input[i].split(""));
  }
  //   console.log(color);
  let dx = [1, 0, -1, 0];
  let dy = [0, 1, 0, -1];
  let vis = Array.from({ length: n }, () => Array.from({ length: n }));
  let vis2 = Array.from({ length: n }, () => Array.from({ length: n }));
  let queue = [];
  let head = 0;
  let tail = 0;
  let cnt = 0;
  let cnt2 = 0;
  //   console.log(vis);
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      const name = color[i][j];
      if (vis[i][j] === undefined) {
        queue.push([i, j]);
        vis[i][j] = 1;
        tail++;
        cnt++;
        while (head < tail) {
          const [x, y] = queue[head];
          head++;
          for (let k = 0; k < 4; k++) {
            let nx = x + dx[k];
            let ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] === 1 || color[nx][ny] !== name) continue;
            queue.push([nx, ny]);
            vis[nx][ny] = 1;
            tail++;
          }
        }
      }
    }
  }
  let changeColor = [];
  for (let i = 1; i < input.length; i++) {
    changeColor.push(input[i].replace(/G/gi, "R").split(""));
  }
  let queue2 = [];
  head = 0;
  tail = 0;
  //   console.log(cnt2);
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      const name = changeColor[i][j];
      //   console.log(name, vis2[i][j]);
      if (vis2[i][j] === undefined) {
        queue2.push([i, j]);
        vis2[i][j] = 1;
        tail++;
        cnt2++;
        while (head < tail) {
          const [x, y] = queue2[head];
          head++;
          for (let k = 0; k < 4; k++) {
            let nx = x + dx[k];
            let ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis2[nx][ny] === 1 || changeColor[nx][ny] !== name) continue;
            queue2.push([nx, ny]);
            vis2[nx][ny] = 1;
            // console.log(nx, ny, vis2);
            tail++;
          }
        }
      }
    }
    // console.log(vis2, cnt2);
  }
  //   console.log(changeColor);
  //   console.log(cnt, cnt2, vis, vis2);
  console.log(`${cnt} ${cnt2}`);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
