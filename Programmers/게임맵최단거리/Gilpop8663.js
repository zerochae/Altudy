/* get input */
let maps = [
  [1, 0, 1, 1, 1],
  [1, 0, 1, 0, 1],
  [1, 0, 1, 1, 1],
  [1, 1, 1, 0, 1],
  [0, 0, 0, 0, 1],
];
/* get input end */

/* solve */
function solution(maps) {
  let answer = Number.MAX_SAFE_INTEGER;
  let dx = [1, 0, 0, -1];
  let dy = [0, 1, -1, 0];

  let queue = [[0, 0, 1]];

  let n = maps.length - 1;
  let m = maps[0].length - 1;

  while (queue.length) {
    let [x, y, count] = queue.shift();
    if (x === n && y === m) return (answer = count);
    for (let k = 0; k < 4; k++) {
      let nx = x + dx[k];
      let ny = y + dy[k];
      if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && maps[nx][ny] === 1) {
        maps[nx][ny] = 0;
        queue.push([nx, ny, count + 1]);
      }
    }
  }
  if (answer === Number.MAX_SAFE_INTEGER) answer = -1;
  return answer;
}

// function solution(maps) {
//   let answer = Number.MAX_SAFE_INTEGER;
//   let dx = [1, 0, 0, -1];
//   let dy = [0, 1, -1, 0];

//   let queue = [];

//   let n = maps.length - 1;
//   let m = maps[0].length - 1;

//   function DFS(x, y, sum) {
//     if (sum > answer) {
//       return;
//     }
//     if (x === n && y === m) {
//       answer = Math.min(answer, sum);
//     } else {
//       for (let i = 0; i < 4; i++) {
//         let nx = x + dx[i];
//         let ny = y + dy[i];
//         if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && maps[nx][ny] === 1) {
//           maps[nx][ny] = 0;
//           DFS(nx, ny, sum + 1);
//           maps[nx][ny] = 1;
//         }
//       }
//     }
//   }
//   maps[0][0] = 0;
//   DFS(0, 0, 1);
//   if (answer === Number.MAX_SAFE_INTEGER) answer = -1;
//   return answer;
// }
/* solve end */

/* print output */
console.log(solution(maps));
/* print output end */
