/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `101
// 1444
// 2567
// 3
// 4
// 510
// 10
// 111
// 131
// 444
// 666
// 4544
// 0`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  //   console.log(input);
  input.pop();
  let pallindromNumber = input;
  //   console.log(pallindromNumber);
  for (let i = 0; i < pallindromNumber.length; i++) {
    if (pallindromNumber[i].length === 1) {
      console.log("yes");
    } else if (pallindromNumber[i].length % 2 !== 0) {
      let mid = (pallindromNumber[i].length - 1) / 2;
      //   console.log(
      //     pallindromNumber[i],
      //     pallindromNumber[i].slice(0, mid),
      //     pallindromNumber[i]
      //       .slice(mid + 1)
      //       .split("")
      //       .reverse()
      //       .join("")
      //   );

      if (
        pallindromNumber[i].slice(0, mid) ===
        pallindromNumber[i]
          .slice(mid + 1)
          .split("")
          .reverse()
          .join("")
      ) {
        console.log("yes");
      } else {
        console.log("no");
      }
    } else if (pallindromNumber[i].length % 2 === 0) {
      let mid = pallindromNumber[i].length / 2;
      //   console.log(
      //     pallindromNumber[i],
      //     pallindromNumber[i].slice(0, mid),
      //     pallindromNumber[i].slice(mid).split("").reverse().join("")
      //   );

      if (
        pallindromNumber[i].slice(0, mid) ===
        pallindromNumber[i].slice(mid).split("").reverse().join("")
      ) {
        console.log("yes");
      } else {
        console.log("no");
      }
    }
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
