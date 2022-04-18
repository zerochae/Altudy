/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `5 17`;

let input = filePath.toString().trim().split(" ");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";
  let queue = [];
  const [n, m] = input.map((item) => +item);
  let dist = Array.from({ length: 100001 }, () => -1);
  let prev = Array.from({ length: 100001 }, () => -1);
  let head = 0;
  let tail = 0;
  queue.push(n);
  dist[n] = 0;
  prev[n] = n;
  tail++;

  while (head < tail) {
    const x = queue[head++];

    for (let nv of [x * 2, x + 1, x - 1]) {
      if (nv < 0 || 100000 < nv) continue;
      if (dist[nv] !== -1) continue;
      dist[nv] = dist[x] + 1;
      queue.push(nv);
      prev[nv] = x;
      tail++;
    }
  }
  //   console.log(console.log(dist[m - 1]));
  let deque = Array.from({ length: 200000 }, () => -1);
  head = 100000;
  tail = 100000;
  const pushFront = (x) => {
    deque[--head] = x;
  };
  pushFront(m);
  while (deque[head] !== n) {
    pushFront(prev[deque[head]]);
  }
  //   console.log(prev[m]);
  //   console.log(deque);
  let answer = "";
  answer += dist[m] + "\n";
  for (let i = head; i < tail; i++) {
    // console.log(deque[i]);
    answer += deque[i] + " ";
  }
  //   answer += dist[m] + "\n" + deque.join(" ");
  console.log(answer);
  //   console.log(input);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
