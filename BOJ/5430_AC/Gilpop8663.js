/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `4
// RDD
// 4
// [1,2,3,4]
// DD
// 1
// [42]
// RRD
// 6
// [1,1,2,3,5,8]
// D
// 0
// []`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  //   const n = +input[0];
  let arr = [];
  let answer = [];
  for (let i = 1; i < input.length; i++) {
    // console.log(input[i], i);
    if (i % 3 === 1) {
      arr = [];
    }
    arr.push(input[i]);
    if (arr.length === 3) {
      //   console.log(arr);
      //   console.log(JSON.parse(arr[2]));
      const n = +arr[1];
      let testArr;
      if (arr[2].length > 1) {
        testArr = JSON.parse(arr[2]);
      } else {
        testArr = [];
      }
      const func = arr[0].split("");
      //   console.log(n, testArr, func);

      let deque = Array.from({ length: 3 * n + 1 });
      let head = n;
      let tail = n;

      const popFront = () => {
        head++;
      };

      const popBack = () => {
        tail--;
      };

      const pushFront = (x) => {
        deque[--head] = x;
      };

      const pushBack = (x) => {
        deque[tail++] = x;
      };

      const front = () => {
        return deque[head];
      };

      const back = () => {
        return deque[tail - 1];
      };

      for (let j = 0; j < testArr.length; j++) {
        pushBack(testArr[j]);
      }
      //   console.log(testArr);
      //   console.log(front(), back());
      //   console.log(testArr, func, n, deque);
      //   console.log(front(), back(), head, tail);

      let reverse = false;
      for (let j = 0; j < func.length; j++) {
        // console.log(func[j]);
        const query = func[j];
        if (query === "R") {
          reverse = !reverse;
        } else if (query === "D") {
          if (reverse) {
            popBack();
          } else {
            popFront();
          }
        }
      }
      let tmpArr = [];
      //   console.log(front(), back(), head, tail);
      //   console.log(tail - head, front(), back(), head, tail);
      if (tail - head >= 0) {
        if (reverse) {
          for (let k = tail - 1; k >= head; k--) {
            //   console.log(deque[k]);
            tmpArr.push(deque[k]);
          }
          answer.push(JSON.stringify(tmpArr));
        } else {
          for (let k = head; k < tail; k++) {
            //   console.log(deque[k]);
            tmpArr.push(deque[k]);
          }
          answer.push(JSON.stringify(tmpArr));
        }
      } else if (tail - head === 0 && deque[tail - 1] && deque[head]) {
        answer.push("[]");
      } else {
        answer.push("error");
      }
    }
  }
  console.log(answer.join("\n"));
};

/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
