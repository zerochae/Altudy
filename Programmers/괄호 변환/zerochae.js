// const p = "(()())()";
// const p = ")(";
const p = "()))((()";

class Stack {
  constructor() {
    this.arr = [];
    this.length = 0;
  }
  push(item) {
    this.arr[this.length++] = item;
  }
  pop() {
    return this.length > 0 ? this.arr[--this.length] : null;
  }
  isEmpty() {
    return this.length === 0;
  }
  top() {
    return this.arr[this.length - 1];
  }
}

function solution(p) {
  return recur(p, []);
}

function recur(str, resultArr) {
  if (isCorrect(str)) return str;

  if (str.length === 0) return "";

  let { u, v } = isBalance(str);


  if (isCorrect(u)) {
    resultArr.push(u);
    return u + recur(v, resultArr);
  } else {
    resultArr.push(v);
    let result = "(" + recur(v, resultArr) + ")";

    u = u.substring(1, u.length - 1);

    for (str of u.split("")) {
      result += str === "(" ? ")" : "(";
    }

    return result;
  }
}

function isCorrect(str) {
  let items = str.split("");

  let stack = new Stack();

  items.map((item) => {
    switch (item) {
      case "(":
        stack.push(item);
        break;
      case ")":
        if (!stack.isEmpty()) stack.pop();
        else {
          return false;
        }
        break;
    }
  });
  return stack.isEmpty();
}

function isBalance(str) {
  let items = str.split("");

  let open = 0;
  let close = 0;
  let u = "";
  let v = "";

  for (let item of items) {
    u += item;
    isWhat(item) ? open++ : close++;
    if (open !== 0 && close !== 0 && open === close) break;
  }

  items.splice(0, u.length);

  for (let item of items) {
    v += item;
  }

  return { u, v };
}

function isWhat(str) {
  switch (str) {
    case "(":
      return true;
    case ")":
      return false;
  }
}

let result = solution(p);

console.log(result);
