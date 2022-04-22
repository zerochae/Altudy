/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `1
// 5 3 6
// 0 2
// 1 2
// 2 2
// 3 2
// 4 2
// 4 0`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  //   const n = +input[0];
  let answer = "";
  let dx = [1, 0, -1, 0];
  let dy = [0, 1, 0, -1];
  let area, vis, areaCnt;
  let cnt = 0;
  let queue = [];
  let head = 0;
  let tail = 0;
  let arrX, arrY;
  for (let i = 1; i < input.length; i++) {
    const [_, __, count] = input[i].split(" ").map((item) => +item);
    if (count !== undefined) {
      [arrX, arrY] = input[i].split(" ").map((item) => +item);
      if (cnt === 1) {
        cnt = cnt + count + 2;
      } else {
        cnt = cnt + count + 1;
      }
      head = 0;
      tail = 0;
      areaCnt = 0;
      queue = [];
      area = Array.from({ length: arrX }, () =>
        Array.from({ length: arrY }, () => 0)
      );
      vis = Array.from({ length: arrX }, () => Array.from({ length: arrY }));
    } else {
      const [X, Y] = input[i].split(" ").map((item) => +item);
      area[X][Y] = 1;
    }
    if (cnt === i) {
      for (let v = 0; v < arrX; v++) {
        for (let b = 0; b < arrY; b++) {
          //   console.log(area[v][b], vis[v][b]);
          if (area[v][b] === 0 || vis[v][b] >= 0) continue;
          queue.push([v, b]);
          vis[v][b] = 1;
          tail++;
          areaCnt++;
          while (head < tail) {
            const [x, y] = queue[head++];
            // console.log(head, tail);
            for (let k = 0; k < 4; k++) {
              let nx = x + dx[k];
              let ny = y + dy[k];
              if (nx >= arrX || nx < 0 || ny >= arrY || ny < 0) continue;
              if (vis[nx][ny] >= 0 || area[nx][ny] !== 1) continue;
              vis[nx][ny] = 1;
              queue.push([nx, ny]);
              tail++;
            }
          }
        }
      }

      //   console.log(vis);
      //   console.log(queue, head, tail);
      //   console.log(input[i]);
      //   console.log(x, y, count);
      //   console.log(areaCnt);
      answer += areaCnt + "\n";
    }
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
