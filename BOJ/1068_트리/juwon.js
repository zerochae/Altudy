const fs = require("fs");
// const input = (
// `5
// -1 0 0 1 1
// 2`
// ).split("\n");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : 
`5
-1 0 0 1 1
2`
).split("\n");

const n = Number(input.shift());
const arr = input.shift().split(" ");
const deleteNode = Number(input.shift());

const solution = (n, arr, deleteNode) => {
    // n 만큼 2차원배열 생성
    let tree = Array.from(Array(n), () => [])
    let res = 0

    let root

    arr.map((el, index) => {
        if (el == -1) {
            root = index
        } else { 
            tree[+el].push(index)
        }
    })

    if (deleteNode != root) { 
        countLeaf(root)
    }

    function countLeaf(root){ 
        const node = tree[root]
        if (node.length === 0 ||
            (node.length == 1 && node[0] == deleteNode)) { 
            res++
            return
        }
        for (let i = 0; i < node.length; i++) { 
            if (node[i] != deleteNode) { 
                countLeaf(node[i])
            }
        }
    }  
    return res
};


const output = solution(n, arr, deleteNode);
console.log(output);

