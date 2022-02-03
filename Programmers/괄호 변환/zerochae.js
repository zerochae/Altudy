function solution(p) {
  if (isCorrect(p)) return p;

  if (p.length === 0) return "";

  let { u, v } = isBalance(p); if (isCorrect(u)) return u + solution(v);

  let result = "(" + solution(v) + ")";

  for (let str of u.substring(1, u.length - 1).split("")) result += str === "(" ? ")" : "(";
  
  return result;
}

function isCorrect(str) {
  
  let stack = [];

  str.split("").map((item) => {
    return item === "(" ? stack.push(item) : stack.length !== 0 ? stack.pop() : false;
  });

  return stack.length === 0;
}

function isBalance(str) {

  let open = 0; let close = 0; let u = ""; let v = "";

  for (let item of str.split("")) {
    u += item; 
    item === "(" ? open++ : close++;
    if (open !== 0 && close !== 0 && open === close) break;
  }
  v = str.substring(u.length);

  return { u, v };
}