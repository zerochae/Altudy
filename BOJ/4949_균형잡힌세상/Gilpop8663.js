/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `So when I die (the [first] I will see in (heaven) is a score list).
// [ first in ] ( first out ).
// Half Moon tonight (At least it is better than no Moon at all].
// A rope may form )( a trail in a maze.
// Help( I[m being held prisoner in a fortune cookie factory)].
// ([ (([( [ ] ) ( ) (( ))] )) ]).
//  .
// (.`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  input.pop();
  //   console.log(input);
  for (let i = 0; i < input.length; i++) {
    // console.log(input[i]);
    let stack = [];
    let noBalance = false;
    for (let k = 0; k < input[i].length; k++) {
      //   console.log(stack);
      if ((input[i][k] === "(") | (input[i][k] === "[")) {
        stack.push(input[i][k]);
      } else if (input[i][k] === ")") {
        if (stack[stack.length - 1] === "(") {
          stack.pop();
        } else {
          noBalance = true;
          break;
        }
      } else if (input[i][k] === "]") {
        if (stack[stack.length - 1] === "[") {
          stack.pop();
        } else {
          noBalance = true;
          break;
        }
      }
    }
    if (input[i][0] === ".") {
      noBalance = true;
    }
    if (stack.length === 0 && !noBalance) {
      console.log("yes");
    } else {
      console.log("no");
    }
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
