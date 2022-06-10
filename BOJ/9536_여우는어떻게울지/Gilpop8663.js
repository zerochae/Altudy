/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `2
// toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot
// dog goes woof
// fish goes blub
// elephant goes toot
// seal goes ow
// what does the fox say?
// toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot
// dog goes woof
// fish goes blub
// elephant goes toot
// seal goes ow
// what does the fox say?`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   console.log(input);
  let n = input[0];
  input.shift();
  //   console.log(input);

  while (n--) {
    let cnt = 1;
    let arr = input[0].split(" ");
    // console.log(arr);
    while (true) {
      if (input[cnt] == "what does the fox say?") {
        input = input.slice(cnt + 1);
        break;
      }

      let aniArr = input[cnt++].split(" ");
      //   console.log(aniArr[2]);
      let newArr = arr.filter((item) => item !== aniArr[2]);
      arr = newArr;
    }
    // console.log(input);
    // console.log(arr);
    let answer = arr.join(" ");
    console.log(answer);
  }
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
