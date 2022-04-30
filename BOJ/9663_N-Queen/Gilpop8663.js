/* get input */
const fs = require("fs");
// const filePath = fs.readFileSync("/dev/stdin");
const filePath = `8`;

const input = +filePath.toString().trim();

//console.log(input);

solution(input);

function solution(A) {
  const visited = new Array(A).fill(0);
  //  console.log(visited);
  let answer = 0;

  dfs(0);

  function dfs(x) {
    if (x === A) {
      // x가 A까지 진행되었디면 1을 더한다.
      answer += 1;
    } else {
      for (let i = 0; i < A; i++) {
        //console.log(visited[x]);
        if (visited[x]) {
          // visited[x]가 존재한다면 계속한다
          continue;
        }
        visited[x] = i; // visited[x]는 행  i 는 열 이라고 가정하였다.
        if (check(x)) dfs(x + 1);
        visited[x] = 0;
      }
    }
  }

  function check(x) {
    for (let i = 0; i < x; i++) {
      //console.log(visited[x]);
      if (visited[x] === visited[i]) {
        // 퀸을 놓을곳 상하 좌우를 비교하고
        return false;
      }
      if (Math.abs(visited[x] - visited[i]) === x - i) {
        // 퀸을 놓을 곳 대각선을 비교한다.
        return false;
      }
    }
    return true; // 위으 두 가지 조건을 피하였다면 퀸을 놓을수 있는 자리임.
  }
  return answer;
}

console.log(solution(input));
