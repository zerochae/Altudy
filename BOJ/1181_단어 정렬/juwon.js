const fs = require("fs");

const input = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : 
`13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours`
).split("\n")

const solution = (input) => {
    const N = +input.shift()

    const temp = Array.from(new Set(input.slice(1, N + 1))).sort((prev, curr) => {
        if (prev.length != curr.length) {
            return prev.length - curr.length;
        } else {
            return prev < curr ? -1 : 1;
        }
    });

    return temp.join("\n")
};


const output = solution(input);
console.log(output)
