/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `5 20
// 99 101 1000 0 97`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let answer = [];
  const person = +input[0].split(" ")[0];
  const area = +input[0].split(" ")[1];
  const howMany = person * area;
  //   console.log(person, area, howMany);
  let newsPapers = input[1].split(" ").map((item) => +item);
  for (let i = 0; i < newsPapers.length; i++) {
    answer.push(newsPapers[i] - howMany);
  }
  console.log(answer.join(" "));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
