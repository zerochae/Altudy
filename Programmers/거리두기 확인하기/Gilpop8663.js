/* get input */
let places = [
  ["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"],
  ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"],
  ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"],
  ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"],
  ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"],
];
/* get input end */

/* solve */

function solution(places) {
  var answer = [];
  answer = places.map((place) => {
    return place.some((row, rowIndex) => {
      //   console.log(row.split(""));
      return row.split("").some((mark, colIndex, rowArr) => {
        // console.log(mark, colIndex, rowArr, rowIndex);
        if (mark === "X") return false;
        // console.log(rowArr[colIndex - 1] || "");
        const countPeopleAround = [
          rowArr[colIndex - 1] || "",
          rowArr[colIndex + 1] || "",
          (place[rowIndex - 1] || "")[colIndex],
          (place[rowIndex + 1] || "")[colIndex],
        ].filter((mark) => mark === "P").length;
        return (
          (mark === "P" && countPeopleAround > 0) ||
          (mark === "O" && countPeopleAround > 1)
        );
      });
    })
      ? 0
      : 1;
  });

  return answer;
}

// function solution(places) {
//   var answer = [];
//   let dx = [1, 0, -1, 0];
//   let dy = [0, -1, 0, 1];
//   for (let i = 0; i < places.length; i++) {
//     // let columnResult = true;
//     let rowResult = true;
//     let menhutonResult = true;
//     for (let j = 0; j < places[i].length; j++) {
//       let count = 0;
//       let rowPrevIndex = -3;
//       let columnPrevIndex = -3;
//       places[i][j] = places[i][j].split("");

//       for (let m = 0; m < 5; m++) {
//         let cnt = 0;
//         if (places[i][j][m] === "O") {
//           for (let k = 0; k <= 3; k++) {
//             let nx = j + dx[k];
//             let ny = m + dy[k];
//             if (nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4) {
//               //   console.log(places[i][nx][ny]);
//               if (places[i][nx][ny] === "P") {
//                 // console.log(places[i][nx][ny]);
//                 cnt++;
//               }
//             }
//           }
//         }
//         if (places[i][j][m] === "P") {
//           for (let k = 0; k <= 3; k++) {
//             let nx = j + dx[k];
//             let ny = m + dy[k];
//             if (nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4) {
//               //   console.log(places[i][nx][ny]);
//               if (places[i][nx][ny] === "P") {
//                 rowResult = false;
//               }
//             }
//           }
//         }
//         // let arr = [];
//         // let rowArr = [];
//         // if (places[i][j].indexOf("P", count) !== -1) {
//         //   //   console.log(
//         //   //     places[i][j].indexOf("P", count),
//         //   //     count,
//         //   //     places[i][j],
//         //   //     rowPrevIndex,
//         //   //     places[i][j].indexOf("P", count) - rowPrevIndex
//         //   //   );
//         //   if (places[i][j].indexOf("P", count) - rowPrevIndex <= 2) {
//         //     // console.log(
//         //     //   places[i][j].indexOf("P", count),
//         //     //   rowPrevIndex,
//         //     //   count,
//         //     //   places[i][j],
//         //     //   j
//         //     // );
//         //     // console.log(
//         //     //   places[i][j].splice(
//         //     //     rowPrevIndex,
//         //     //     places[i][j].indexOf("P", count)
//         //     //   )
//         //     // );
//         //     rowArr = places[i][j]
//         //       .slice()
//         //       .splice(rowPrevIndex, places[i][j].indexOf("P", count));
//         //     // console.log(rowArr);
//         //     if (rowArr.indexOf("X") === -1) {
//         //       rowResult = false;
//         //     }
//         //   }
//         //   rowPrevIndex = places[i][j].indexOf("P", count);
//         //   count = places[i][j].indexOf("P", count) + 1;
//         //   //   count++;
//         //   //   console.log(count);
//         // }
//         // if (places[i][m][j] === "P") {
//         //   if (m - columnPrevIndex <= 2) {
//         //     for (
//         //       let s = columnPrevIndex < 0 ? 0 : columnPrevIndex + 1;
//         //       s < m;
//         //       s++
//         //     ) {
//         //       //   console.log(places[i][s][j], m, columnPrevIndex);
//         //       arr.push(places[i][s][j]);
//         //     }
//         //     if (arr.indexOf("X") === -1) {
//         //       columnResult = false;
//         //     }
//         //   }
//         //   columnPrevIndex = m;
//         // }
//         // if (cnt >= 2) {
//         //   menhutonResult = false;
//         // }
//       }
//     }
//     if (rowResult && menhutonResult) {
//       answer.push(1);
//     } else {
//       answer.push(0);
//     }
//     // console.log(rowResult);
//     // console.log(columnResult);
//     // console.log(menhutonResult);
//   }
//   return answer;
// }
// // function solution(places) {
// //   var answer = [];
// //   let dx = [];
// //   let dy = [];
// //   for (let i = -1; i <= 1; i++) {
// //     for (let j = -1; j <= 1; j++) {
// //       if (i === 0 && j === 0) continue;
// //       if (Math.abs(i) + Math.abs(j) === 1) {
// //         dx.push(i);
// //         dy.push(j);
// //       }
// //     }
// //   }

// //   for (let n = 0; n < places.length; n++) {
// //     let sideOk = false;
// //     let oOk = false;
// //     for (let i = 0; i < places[n].length; i++) {
// //       for (let j = 0; j < 5; j++) {
// //         if (sideOk === 1) return;
// //         let cnt = 0;
// //         if (places[n][i][j] === "P") {
// //           for (let k = 0; k < dx.length; k++) {
// //             let nx = i + dx[k];
// //             let ny = j + dy[k];
// //             if (
// //               nx >= 0 &&
// //               nx <= 4 &&
// //               ny >= 0 &&
// //               ny <= 4 &&
// //               places[n][nx][ny] === "P"
// //             ) {
// //               sideOk === true;
// //             }
// //           }
// //         }
// //         if (places[n][i][j] === "O") {
// //           for (let k = 0; k < dx.length; k++) {
// //             let nx = i + dx[k];
// //             let ny = j + dy[k];
// //             if (
// //               nx >= 0 &&
// //               nx <= 4 &&
// //               ny >= 0 &&
// //               ny <= 4 &&
// //               places[n][nx][ny] === "P"
// //             ) {
// //               cnt++;
// //               //   console.log(cnt === 2);
// //               if (cnt === 2) {
// //                 oOk = true;
// //               }
// //             }
// //           }
// //         }
// //       }
// //     }
// //     // console.log(sideOk);
// //     // console.log(oOk);
// //     if (!sideOk && !oOk) answer.push(1);
// //     else {
// //       answer.push(0);
// //     }
// //   }

// //   return answer;
// // }

// //   console.log(dx, dy);
// //   //   function DFS(x, y, i) {
// //   //     // console.log(x, y);
// //   //     for (let k = 0; k < dx.length; k++) {
// //   //       let nx = x + dx[k];
// //   //       let ny = y + dy[k];
// //   //       if (nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4) {
// //   //         let rowPrevStr;
// //   //         let rowNextStr;
// //   //         let columnNextStr;
// //   //         let columnPrevStr;
// //   //         if (k === 4 && places[i][nx][ny] === "P") {
// //   //           console.log("여기요");
// //   //         }
// //   //         if (places[i][nx][ny] === "P") {
// //   //           //   console.log(rowStr, y, ny);
// //   //           rowPrevStr = places[i][nx][ny + 1];
// //   //           rowNextStr = places[i][nx][ny + 2];
// //   //           columnPrevStr = places[i][nx + 1][ny];
// //   //           columnNextStr = places[i][nx + 2][ny];
// //   //           //   console.log(columnNextStr, columnPrevStr, "asd");
// //   //           //   console.log(rowStr.indexOf("P"), rowStr.indexOf("X"));
// //   //           //   console.log(places[i][x], places[i][nx][ny], nx, y, ny);
// //   //           if (
// //   //             rowPrevStr &&
// //   //             rowNextStr &&
// //   //             rowPrevStr !== "X" &&
// //   //             rowNextStr !== "X"
// //   //           ) {
// //   //             console.log("가로임", x, y, places[i][x]);
// //   //             return false;
// //   //           } else if (
// //   //             columnNextStr &&
// //   //             columnPrevStr &&
// //   //             columnPrevStr !== "X" &&
// //   //             columnNextStr !== "X"
// //   //           ) {
// //   //             console.log("세로임", x, y, places[i][x]);
// //   //             return false;
// //   //           } else if (
// //   //             places[i][x][ny] !== "X" &&
// //   //             places[i][nx][y] !== "X" &&
// //   //             k === 3
// //   //           ) {
// //   //             return false;
// //   //           }
// //   //         }
// //   //       }

// //   //       //   if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] === 1) {
// //   //       //     DFS(nx, ny);
// //   //       //   }
// //   //     }
// //   //     return true;
// //   //   }

// //   //   for (let i = 0; i < places.length; i++) {
// //   //     let result = true;
// //   //     for (let j = 0; j < places[i].length; j++) {
// //   //       for (let k = 0; k < 5; k++) {
// //   //         if (result === false) continue;
// //   //         if (places[i][j][k] === "P") {
// //   //           //   console.log(places[i][j][k], j, k);
// //   //           result = DFS(j, k, i);
// //   //           //   console.log(result, "result임");
// //   //         }
// //   //       }
// //   //     }
// //   //     if (result) answer.push(1);
// //   //     else if (!result) answer.push(0);
// //   //   }
/* solve end1 */

/* print output */
console.log(solution(places));
/* print output end */
