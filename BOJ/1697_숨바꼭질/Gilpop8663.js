/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
const filePath = `5 17`;

const input = filePath
  .toString()
  .trim()
  .split(" ")
  .map((item) => +item);
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  // console.log(input);
  const n = +input[0];
  const m = +input[1];
  let dist = Array.from({ length: 100001 }, () => -1);
  let queue = [];
  dist[n] = 0;
  queue.push(n);

  while (dist[m] === -1) {
    let cur = queue.shift();
    for (let nxt of [cur - 1, cur + 1, cur * 2]) {
      if (nxt < 0 || nxt > 100000) continue;
      if (dist[nxt] !== -1) continue;
      dist[nxt] = dist[cur] + 1;
      queue.push(nxt);
    }
    // console.log(queue);
  }
  console.log(dist[m]);
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
