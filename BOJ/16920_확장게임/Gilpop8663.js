/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `3 3 2
// 1 1
// 1..
// ...
// ..2`;

let input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";
  let [n, m, p] = input[0].split(" ").map((item) => +item);
  let canExtend = Array.from({ length: 1002 }, () =>
    Array.from({ length: 1002 })
  );

  let board = [];

  let dx = [1, 0, -1, 0];
  let dy = [0, 1, 0, -1];

  let step = Array.from({ length: 10 }, () => 0);
  let area = Array.from({ length: 10 }, () => 0);

  for (let i = 0; i < p; i++) {
    step[i + 1] = +input[1].split(" ")[i];
  }

  //   console.log(step);
  for (let i = 2; i < input.length; i++) {
    board.push(input[i].split(""));
  }

  //   console.log(board);
  let queue = Array.from({ length: 10 }, () => []);
  let head = 0;
  let tail = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      const ch = board[i][j];
      if (ch === ".") canExtend[i][j] = 1;
      else if (ch === "#") canExtend[i][j] = 0;
      else {
        canExtend[i][j] = 0;
        queue[ch].push([i, j, 0]);
        area[ch] += 1;
      }
    }
  }
  while (1) {
    let isExtend = 0;

    for (let i = 1; i <= p; i++) {
      head = 0;
      tail = queue[i].length;
      let nextQ = [];
      while (head < tail) {
        // console.log("실행");
        let [curX, curY, curStep] = queue[i][head++];
        // console.log(curStep, step[i], queue[i], area[i]);
        if (curStep >= step[i]) {
          nextQ.push([curX, curY, 0]);
          continue;
        }

        for (let dir = 0; dir < 4; dir++) {
          let nx = curX + dx[dir],
            ny = curY + dy[dir];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (canExtend[nx][ny] === 0) continue;
          queue[i].push([nx, ny, curStep + 1]);
          tail++;
          canExtend[nx][ny] = 0;
          area[i]++;
          isExtend = 1;
        }
        // console.log(area);
      }
      queue[i] = nextQ;
      //   console.log(head, tail, queue[i]);
    }
    if (!isExtend) break;
  }

  let answer = "";
  for (let i = 1; i <= p; i++) {
    answer += area[i] + " ";
  }
  console.log(answer);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
