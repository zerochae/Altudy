/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `10
// 6 3 2 10 10 10 -10 -10 7 3
// 8
// 10 9 -5 2 3 4 5 -10`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  const n = +input[0];
  let myCard = input[1].split(" ");
  const m = +input[2];
  const whatCard = input[3].split(" ");

  let howMany = Array.from({ length: m }, () => 0);
  //   console.log(myCard);
  for (let i = 0; i < n; i++) {
    if (howMany[myCard[i]] > 0) {
      howMany[myCard[i]] += 1;
    } else howMany[myCard[i]] = 1;
  }
  //   console.log(howMany);
  let answer = [];
  for (let i = 0; i < m; i++) {
    if (howMany[whatCard[i]] === undefined) {
      answer.push(0);
    } else {
      answer.push(howMany[whatCard[i]]);
    }
  }
  console.log(answer.join(" "));
  //   for (let i = 0; i < m; i++) {
  //     let count = 0;
  //     for (let j = 0; j < n; j++) {
  //       if (myCard[j] === whatCard[i]) {
  //         count++;
  //       }
  //     }
  //     howMany.push(count);
  //   }
  //   console.log(howMany.join(" "));
}; /* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
