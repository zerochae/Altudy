/* get input */
let p = ")()(()";
/* get input end */

/* solve */
function solution(p) {
  var answer = "";
  if (p === "") answer = "";

  let u, v;
  for (let i = 2; i <= p.length; i++) {
    if (isCheckTrue(p.slice(0, i)) === true) {
      u = p.slice(0, i);
      v = p.slice(i);
      break;
    }
  }
  //   answer += "(" + u;
  //   console.log(u, v, "uv임");
  if (isCollect(u) === true) {
    let str = solution(v);
    // console.log(u, "u임");
    answer += u + str;
  } else if (isCollect(u) === false) {
    u = u.slice(1, -1).split("");
    for (let i = 0; i < u.length; i++) {
      if (u[i] === ")") u[i] = "(";
      else if (u[i] === "(") u[i] = ")";
    }
    u = u.join("");
    // console.log(u, v, "u임");
    let strr = solution(v);
    let str = "(" + strr + ")" + u;
    answer += str;
  }

  return answer;
}

function isCollect(arr) {
  if (!arr) return;
  let queue = [];
  for (let i = 0; i < arr.length; i++) {
    if (queue[queue.length - 1] === "(" && arr[i] === ")") {
      queue.pop();
    } else {
      queue.push(arr[i]);
    }
  }
  if (queue.length > 0) return false;
  else if (queue.length === 0) return true;
}

function isCheckTrue(arr) {
  if (!arr) return false;
  let left = 0;
  let right = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === "(") left++;
    else if (arr[i] === ")") right++;
  }
  if (left === right && left > 0 && right > 0) return true;
  else return false;
}

/* solve end */

/* print output */
console.log(solution(p));
/* print output end */
