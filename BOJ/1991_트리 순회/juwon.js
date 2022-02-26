const fs = require("fs");
const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : 
`7
A B C
B D .
C E F
E . .
F . G
D . .
G . .`
).split("\n");

const n = Number(input.shift());

const solution = (n, input) => {
    const tree = [];
    let res = '';
    
    for(let i = 0; i < n; i++){
        const [node, left, right] = input[i].split(' ')
        tree[node] = [left, right]
    }

    // preorder 전위순회 VLR
    const preorder = (start) => { 
        if(start === '.') return
        const [left, right] = tree[start]
        res += start
        preorder(left)
        preorder(right)
    }
    
    // inorder 중위 순회 LVR
    const inorder = (start) => {
        if(start === '.') return
        const [left, right] = tree[start]
        inorder(left)
        res += start
        inorder(right)
    }

    // postorder 후위 순회 LRV
    const postorder = (start) => {
        if(start === '.') return
        const [left, right] = tree[start]
        postorder(left)
        postorder(right)
        res += start
    }

    preorder('A')
    res += '\n'
    inorder('A')
    res += '\n'
    postorder('A')

    return res
};

const output = solution(n, input);
console.log(output);

