/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `3
// 1 0
// 5
// 4 2
// 1 2 3 4
// 6 0
// 1 1 9 1 1 1`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  let count = +input[0];
  for (let i = 1; i < input.length; i = i + 2) {
    let N = input[i].split(" ")[0];
    let M = input[i].split(" ")[1];
    let papers = input[i + 1].split(" ");
    let paperCount = [];
    for (let j = 0; j < papers.length; j++) {
      paperCount.push({ index: j, value: +papers[j] });
    }
    let stack = [...paperCount];
    let index = 0;
    // console.log(paperCount);
    let popNum;
    let target = paperCount[M];
    let cnt = 0;
    // console.log(target);
    while (popNum?.index === target.index ? false : true) {
      let arr = [...stack];
      let newArr = arr.sort((a, b) => a.value - b.value);
      //   console.log(stack);
      if (stack[0].value >= newArr[newArr.length - 1].value) {
        popNum = stack[0];
        stack.shift();
        cnt++;
      } else if (stack[0].value < newArr[newArr.length - 1].value) {
        stack.push(stack[0]);
        stack.shift();
      }
    }
    // console.log(popNum, target, cnt);
    console.log(cnt);
  }
};
// };
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
