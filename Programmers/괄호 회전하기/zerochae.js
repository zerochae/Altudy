/* get input */
const s = "}}}";
/* get input end */

/* solve */
const solution = (s) => {
  let count = 0;
  let length = s.length;
  let str = s.split("");

  const rotate = (str) => {
    const stack = [];

    str.some((el) => {

      const open = el === "[" || el === "(" || el === "{";
      const close =
        (stack.length !== 0 && stack[stack.length - 1] === "{" && el === "}") ||
        (stack[stack.length - 1] === "[" && el === "]") ||
        (stack[stack.length - 1] === "(" && el === ")");

      open ? stack.push(el) : close ? stack.pop() : stack.push(false);
    });
    stack.length === 0 && !stack.includes(false) ? count++ : null;
  };

  while (length --> 0) {
    rotate(str);
    str = [...str.pop(), ...str];
  }

  return count;
};
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
