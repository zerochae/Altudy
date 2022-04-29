/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
const filePath = `27`;

const input = filePath.toString().trim();

let answer = "";

const star = (i, j, num) => {
  if (i % 3 === 1 && j % 3 === 1) {
    // (1,1) , (1,4), (1,7) ,(4,1), ... 등 공백의 위치를 좌표로 계산한다면 %3 을 하였을 때 항상 나머지가 1이다
    answer += " ";
  } else {
    if (num === 1) {
      // 위의 조건에 부합하지 않고 num이 /3을  n번 하여 1이 되었다면 *을 출력한다
      answer += "*";
    } else {
      star(Math.floor(i / 3), Math.floor(j / 3), Math.floor(num / 3)); // num이 1이 아니라면 3으로 나누어서 재귀 알고리즘을 한다.
      //console.log("what");
    }
  }
};

for (let i = 0; i < input; i++) {
  // i = 0,1,2,3,4,5...input
  for (let j = 0; j < input; j++) {
    // j =0.1.2.3.4.5 ... input
    star(i, j, input); // 각각의 좌표일 때 함수 실행
  }
  answer += "\n";
}
console.log(answer);
