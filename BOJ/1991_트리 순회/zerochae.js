/* get input */
const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `7
A B C
B D .
C E F
E . .
F . G
D . .
G . .`
).split("\n");
/* get input end */

/* set param */
const n = input.shift();
const nodes = [...input];
const tree = {};
const result = [];
/* set param end */

/* solve */
const solution = (root) => {

  nodes.map(el=>{
    const [node,left,right] = el.split(" ");
    tree[node] = {
      left: left,
      right: right
    }
  })
  return search(root);
};

const search = (root) => {
  preOrder(root)
  result.push('\n')
  inOrder(root)
  result.push('\n')
  postOrder(root)
  return result.join("");
}

const preOrder = (node) => {
  if (node === ".") return;

  const {left,right} = tree[node];
  result.push(node);
  preOrder(left);
  preOrder(right);
};

const inOrder = (node) => {
  if (node === ".") return;

  const {left,right} = tree[node];
  inOrder(left);
  result.push(node);
  inOrder(right);
};

const postOrder = (node) => {
  if (node === ".") return;

  const {left,right} = tree[node];
  postOrder(left);
  postOrder(right);
  result.push(node);
};
/* solve end */

/* print output */
const output = solution('A');
console.log(output);
/* print output end */
