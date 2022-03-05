const fs = require("fs");
const input = (
`5
5
2
3
4
1`
).split("\n");
// const input = (
//   process.platform === "linux"
//     ?fs.readFileSync("/dev/stdin").toString()
//     : 
// `5
// 5
// 2
// 3
// 4
// 1`
// ).split("\n");

function solution(N, ...nums) {
  return nums.sort((a, b) => a - b).join("\n");
}

console.log(solution(...input));


const solution2 = (input) => {
    const n = +input.shift();
    let res = ''
    for (let i = 0; i < n - 1; i++) { 
        for (let j = i + 1; j < n; j++){
            if (input[i] > input[j]) { 
                let temp = input[j]
                input[j] = input[i]
                input[i] = temp
            }
        }
    }

    for (let i = 0; i < input.length; i++) { 
        res += +input[i]
        if(i < input.length - 1) res += "\n"
    }
    return res
};

const output = solution2(input);
console.log(output);

