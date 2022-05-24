/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `Union of Computer Programming Contest club contest`;
const filePath = `University Computer Programming`;

let input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";

  let str = "";
  let cnt = 0;
  for (let i = 0; i < input.length; i++) {
    if (cnt === 0 && input[i] === "U") {
      str += input[i];
      cnt++;
    } else if (cnt === 1 && input[i] === "C") {
      str += input[i];
      cnt++;
    } else if (cnt === 2 && input[i] === "P") {
      str += input[i];
      cnt++;
    } else if (cnt === 3 && input[i] === "C") {
      str += input[i];
      cnt++;
      break;
    }
  }

  //   console.log(cnt, str);
  if (cnt === 4) {
    console.log("I love UCPC");
  } else {
    console.log("I hate UCPC");
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
