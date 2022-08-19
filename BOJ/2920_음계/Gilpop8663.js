/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `8 1 7 2 6 3 5 4`;

const input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let ascending = "1 2 3 4 5 6 7 8";
  let descending = "8 7 6 5 4 3 2 1";
  //   console.log(input, ascending, descending);
  //   console.log([1] === [1]);
  if (input === ascending) {
    console.log("ascending");
  } else if (input === descending) {
    console.log("descending");
  } else {
    console.log("mixed");
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
