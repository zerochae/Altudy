/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `1 2`;

let input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";
  //   console.log(input);
  const [n, m] = input.map((item) => +item);
  //   console.log(n, m, input);
  let deque = Array.from({ length: 200000 });
  let dist = Array.from({ length: 200000 }, () => -1);
  let head = 100000;
  let tail = 100000;

  const pushFront = (x) => {
    deque[--head] = x;
  };
  const pushBack = (x) => {
    deque[tail++] = x;
  };

  pushBack(n);
  dist[n] = 0;
  while (head < tail) {
    let x = deque[head++];
    if (x === m) break;
    if (dist[2 * x] === -1 && 2 * x <= 200000) {
      dist[2 * x] = dist[x];
      pushFront(2 * x);
    }
    for (let nxt of [x - 1, x + 1]) {
      //   console.log(nxt);
      if (nxt < 0 || nxt >= 200000 || dist[nxt] !== -1) continue;
      dist[nxt] = dist[x] + 1;
      pushBack(nxt);
    }
  }
  //   console.log(deque[100000]);
  console.log(dist[m]);
};
// 0-1 BFS로 해결한 풀이
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
