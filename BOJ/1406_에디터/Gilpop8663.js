/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `abcd
// 3
// P x
// L
// P y`;

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

  //   console.log(input);
  const str = input[0];
  const n = +input[1];

  const ll = new LinkedList();
  ll.init();

  for (const c of str) {
    ll.add(c);
  }
  for (let i = 2; i < n + 2; i++) {
    // console.log(input[i]);
    const query = input[i].split(" ");

    switch (query[0]) {
      case "L":
        ll.prev();
        break;
      case "D":
        ll.next();
        break;
      case "B":
        ll.del();
        break;
      case "P":
        ll.add(query[1]);
        break;
    }
  }
  let answer = [];
  ll.begin();
  while (!ll.isBegin()) {
    ll.prev();
    // console.log(ll.get());
    answer.push(ll.get());
  }
  console.log(answer.reverse().join(""));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
