/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `10`;

const input = filePath.toString().trim();
/* get input end */

/* set param */

/* set param end */

/* solve */ //1 2 3 4 5 6  3 4 5 6 2  5 6 2 4  2 4 6  6 4  4

const solution = (input) => {
  "use strict";
  const n = +input;
  let arr = Array.from({ length: n }, (v, i) => i + 1);
  // console.log(arr);
  let head = 0;
  let tail = n;
  // console.log(head, tail);
  while (tail - head > 1) {
    head++;
    arr[tail++] = arr[head++];
    if (tail - head <= 1) {
      console.log(arr[tail - 1]);
      // console.log(arr, head, tail);
      break;
    }
    // console.log(head, tail, arr);
  }
  if (n === 1) console.log(1);
};
//   let queue = Array.from({ length: +input }, (v, i) => i + 1);
//   // console.log(queue);
//   while (queue.length > 1) {
//     queue.push(queue[1]);
//     // queue = [...queue.slice(2)];
//     queue.shift();
//     queue.shift();
//   }
//   console.log(queue[0]);
// };
// const solution = (input) => {
//   // console.log(input);
//   const size = +input;
//   let cq = Array.from({ length: size }, () => null);

//   let front = 0;
//   let rear = 0;

//   const isEmpty = () => {
//     rear === front;
//   };

//   const isFull = () => {
//     return (rear + 1) % size === front;
//   };

//   const enqueue = (item) => {
//     if (isFull()) {
//       console.log("큐가 가득참");
//       return;
//     }
//     cq[item] = item;
//     rear = (rear + 1) % size;
//     return item;
//   };

//   const dequeue = () => {
//     if (isEmpty()) {
//       console.log("큐가 비어있음");
//       return;
//     }
//     const val = cq[front];
//     cq[front] = null;
//     front = (front + 1) % size;
//     return val;
//   };

// };

// };
/* solve end */

/* print output */
const output = solution(input);
// for (let i = 1; i <= 1000; i++) {
//   const output = solution(i);
// }
// console.log(output);
/* print output end */
