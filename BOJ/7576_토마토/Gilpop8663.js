/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `2 2
// 1 -1
// -1 1`;

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
  const dx = [1, 0, -1, 0];
  const dy = [0, 1, 0, -1];
  //   console.log(n, m);
  let answer = 0;
  let bucket = [];
  let queue = [];
  let head = 0;
  let tail = 0;

  let dist = Array.from({ length: m }, () => Array.from({ length: n }));
  for (let i = 1; i < input.length; i++) {
    bucket.push(input[i].split(" ").map((item) => +item));
  }
  //   console.log(bucket);
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (bucket[i][j] === 1) {
        queue.push([i, j]);
        tail++;
        dist[i][j] = 0;
      } else if (bucket[i][j] === 0) {
        dist[i][j] = -1;
      }
    }
  }
  while (head < tail) {
    const [x, y] = queue[head++];
    // console.log(queue);
    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      //   console.log(dist[nx][ny]);
      if (dist[nx][ny] >= 0 || dist[nx][ny] === undefined) continue;
      dist[nx][ny] = dist[x][y] + 1;
      queue.push([nx, ny]);
      tail++;
      //   console.log(queue);
    }
  }

  //   console.log(dist);
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (dist[i][j] === -1) {
        answer = -1;
      } else if (dist[i][j] === undefined) {
        continue;
      } else if (answer !== -1) {
        answer = Math.max(answer, dist[i][j]);
      }
    }
  }

  console.log(answer);
  //   console.log(bucket, cnt);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
