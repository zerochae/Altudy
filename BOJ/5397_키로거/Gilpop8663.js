/* get input */
const fs = require("fs");
// /const filePath = fs.readFileSync("/dev/stdin");
const filePath = `2
<<BP<A>>sa>s>s>s><<-Cd-
ThIsIsS3Cr3t`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */
const solution = (input) => {
  "use strict";
  class Node {
    constructor() {
      this.data = -1;
      this.next = null;
      this.prev = null;
    }
  }

  class LinkedList {
    constructor() {
      this.head = null;
      this.cur = null;
    }

    init() {
      this.head = new Node();
      this.cur = this.head;
    }

    next() {
      if (this.cur.next === null) return;

      this.cur = this.cur.next;
    }

    prev() {
      if (this.cur.prev === null) return;
      this.cur = this.cur.prev;
    }

    del() {
      if (this.cur.prev === null) return;

      let delNode = this.cur.prev;
      if (delNode.prev !== null) delNode.prev.next = delNode.next;

      if (delNode.next !== null) delNode.next.prev = delNode.prev;
    }

    add(data) {
      let newNode = new Node();
      newNode.data = data;
      newNode.next = this.cur;
      newNode.prev = this.cur.prev;

      if (this.cur.prev !== null) {
        this.cur.prev.next = newNode;
      }
      this.cur.prev = newNode;
    }

    get() {
      if (this.cur === null) return;

      return this.cur.data;
    }

    isBegin() {
      return this.cur.prev === null;
    }
    begin() {
      this.cur = this.head;
    }
  }

  const n = +input[0];
  input.shift();
  let answer = "";
  for (let i = 0; i < n; i++) {
    let t = 0;
    let arr = [];
    const ll = new LinkedList();
    ll.init();
    for (let j = 0; j < input[i].length; j++) {
      //   console.log(input[i][j]);
      const query = input[i][j];
      switch (query) {
        case "<":
          ll.prev();
          break;
        case ">":
          ll.next();
          break;
        case "-":
          ll.del();
          break;
        default:
          ll.add(query);
          break;
      }
    }
    ll.begin();
    while (!ll.isBegin()) {
      ll.prev();
      arr.push(ll.get());
    }
    // console.log(arr.reverse().join(""));
    // console.log(arr.join(""));
    answer += arr.reverse().join("") + "\n";
  }
  console.log(answer);
};

// const solution = (input) => {
//   "use strict";

//   const n = +input[0];
//   input.shift();
//   let answer = "";
//   for (let i = 0; i < n; i++) {
//     let t = 0;
//     let stack1 = [];
//     let stack2 = [];

//     for (let j = 0; j < input[i].length; j++) {
//       //   console.log(input[i][j]);
//       const query = input[i][j];
//       switch (query) {
//         case "<":
//           if (stack1.length) {
//             stack2.push(stack1.pop());
//           }
//           break;
//         case ">":
//           if (stack2.length) {
//             stack1.push(stack2.pop());
//           }
//           break;
//         case "-":
//           if (stack1.length) {
//             stack1.pop();
//           }
//           break;
//         default: {
//           stack1.push(query);
//           break;
//         }
//       }
//       console.log(stack1, stack2);
//     }
//     // console.log(arr.reverse().join(""));
//     // console.log(arr.join(""));
//     // answer += arr.reverse().join("") + "\n";
//   }
//   console.log(answer);
// };

// const solution = (input) => {
//   "use strict";
//   const n = +input[0];
//   input.shift();
//   let answer = "";
//   for (let i = 0; i < n; i++) {
//     let t = 0;
//     let arr = [];
//     for (let j = 0; j < input[i].length; j++) {
//       //   console.log(input[i][j]);
//       //   console.log(t, input[i][j], arr);
//       if (input[i][j] === "<") {
//         if (arr.length) {
//           if (t > 0) t--;
//           else t = 0;
//         }
//       } else if (input[i][j] === ">") {
//         if (arr.length) {
//           if (t < arr.length) t++;
//           else t = arr.length;
//         }
//       } else if (input[i][j] === "-") {
//         if (arr.length) {
//           arr.splice(t - 1, 1);
//           t--;
//         }
//       } else {
//         if (arr.length) {
//           arr.splice(t, 0, input[i][j]);
//           t++;
//         } else {
//           arr.push(input[i][j]);
//           t++;
//         }
//       }
//     }
//     // console.log(arr.join(""));
//     answer += arr.join("") + "\n";
//   }
//   console.log(answer);
// };
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
