// node filename.js in same dir

const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

const input = fs.readFileSync(filePath).toString().split('\n');

// +input?? Number?
const N = +input.shift();

function solution(N, input) { 
    const stack = [];
    const result = [];
    
    for (let i = 0;i < N;++i) {
        
        const [cmd, val] = input[i].split(' ');

        switch (cmd) { 
            case 'push': 
                stack.push(+val);
                break;
            case 'pop':
                if (stack.length === 0) {
                    result.push(-1);
                    break;
                } 
                result.push(stack.pop());
                break;
            case 'size': 
                result.push(stack.length);
                break;
            case 'empty': 
                if (stack.length === 0) { 
                    result.push(1);
                } else { 
                    result.push(0);
                } 
                break;
            case 'top': 
                if (stack.length === 0) { 
                    result.push(-1);
                    break;
                } 
                result.push(stack[stack.length - 1]);
                break;
        } 
    } 
    return result.join('\n');
} 
console.log(solution(N, input));

