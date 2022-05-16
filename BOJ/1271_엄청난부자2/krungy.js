let input = require("fs").readFileSync("/dev/stdin").toString().split(" ");

//input = 5, 20, 10 ,35, 30, 7
let money = BigInt(input[0]);
let mon = BigInt(input[1]);
let ans1 = money / mon;
let ans2 = money % mon;

console.log(ans1 + "\n" + ans2);
