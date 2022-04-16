/* get input */
const fs = require("fs");

// 백준용
const filePath = fs.readFileSync("/dev/stdin");

// 비쥬얼스튜디오 인풋값
// const filePath = `10 10
// 1 6 3 2 7 9 8 4 10 5`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

const solution = (input) => {
  "use strict";
  input[0] = input[0].split(" ");
  const n = +input[0][0];
  const targetN = +input[0][1];

  const target = input[1].split(" ").map((item) => +item);
  //   console.log(n, targetN, target);

  let answer = 0;
  let arr = Array.from({ length: 100000 }, () => 0);
  let head = 5000;
  let tail = 5000;

  const popBack = () => {
    tail--;
  };
  const popFront = () => {
    head++;
  };
  const pushFront = (x) => {
    arr[--head] = x;
  };
  const pushBack = (x) => {
    arr[tail++] = x;
  };

  const front = () => {
    return arr[head];
  };
  const back = () => {
    return arr[tail - 1];
  };

  const size = () => {
    return tail - head;
  };

  //   console.log(arr);
  for (let i = 1; i <= n; i++) {
    pushBack(i);
  }

  for (let i = 0; i < targetN; i++) {
    const query = target[i];
    const nowArr = arr.slice(head, tail);
    const findIndex = nowArr.findIndex((item) => item === query);
    // console.log(nowArr, findIndex, size(), front(), query);
    // console.log(answer, nowArr, query);
    while (front() !== query) {
      if (findIndex < parseInt(+size() / 2 + 1)) {
        pushBack(front());
        popFront();
      } else {
        pushFront(back());
        popBack();
      }
      answer++;
      //   console.log(findIndex, query, size(), parseInt(size() / 2 + 1));
    }
    popFront();
  }
  //   console.log(arr);

  //결과값 출력
  //   console.log(size());
  //   console.log(cnt);
  console.log(answer);

  //   }
};

/* solve end */

/* print output */
const output = solution(input);
// for (let i = 1; i <= 1000; i++) {
//   const output = solution(i);
// }
// console.log(output);
/* print output end */
