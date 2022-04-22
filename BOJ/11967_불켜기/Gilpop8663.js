/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `3 6
// 1 1 1 2
// 2 1 2 2
// 1 1 1 3
// 2 3 3 1
// 1 3 1 2
// 1 3 2 1`;

let input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";
  let [n, m] = input[0].split(" ").map((item) => +item);
  //   console.log(n);
  let adj = Array.from({ length: 101 }, () =>
    // 방에 어떤 스위치가 있는지
    Array.from({ length: 101 }, () => [])
  );
  let board = Array.from({ length: 101 }, () =>
    //방에 불이 켜져 있는지
    Array.from({ length: 101 }, () => 0)
  );
  let vis = Array.from({ length: 101 }, () => Array.from({ length: 101 })); // 방에 방문했는지
  let dx = [1, 0, -1, 0];
  let dy = [0, 1, 0, -1];

  const OOB = (a, b) => {
    return a < 1 || a > n || b < 1 || b > n;
  };
  const isClose = (x, y) => {
    //(1,1)에서 도달가능한 칸인지
    for (let dir = 0; dir < 4; dir++) {
      let nx = x + dx[dir];
      let ny = y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (vis[nx][ny]) return true;
    }
    return false;
  };
  m++;

  while (m-- > 1) {
    // console.log(input[m]);
    const [x, y, a, b] = input[m].split(" ").map((item) => +item);
    adj[x][y].push([a, b]);
  }
  //   console.log(adj[1]);
  let queue = [];
  let head = 0;
  let tail = 0;
  queue.push([1, 1]);
  board[1][1] = 1; //방에 불이 켜져있고
  vis[1][1] = true; //방문했음

  tail++;
  while (head < tail) {
    const [curX, curY] = queue[head++];
    // console.log(adj[curX][curY]);
    for (let nxt of adj[curX][curY]) {
      // 스위치로 킨 방에서 현재 방문 가능한지
      const [nxtX, nxtY] = nxt;
      if (vis[nxtX][nxtY] !== undefined) continue; // 방문했다면 가지 않는다
      if (isClose(nxtX, nxtY)) {
        // 불켜진 방에서 현재 갈 수 있는지
        vis[nxtX][nxtY] = 1;
        queue.push([nxtX, nxtY]);
        tail++;
      }
      board[nxtX][nxtY] = 1;
    }
    for (let dir = 0; dir < 4; dir++) {
      // 새롭게 켜진 방으로 인해 현재 위치에서 새롭게 갈수 있는지 체크
      let nx = curX + dx[dir];
      let ny = curY + dy[dir];
      if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] === 0) continue; // 가본적이 있다면 가지 않는다
      vis[nx][ny] = 1;
      queue.push([nx, ny]);
      tail++;
    }
  }

  let answer = 0;
  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= n; j++) {
      answer += board[i][j];
    }
  }
  //   console.log(queue, answer);
  console.log(answer);
};

/*
마치 인접 리스트 방식과 같이 연결 상태를 표현하는게 좋고(adj 배열)
새롭게 불을 밝힌 방에 대해서 해당 방이 방문 가능한 곳인 경우에만 큐에 넣어주어야 한다.
*/
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
