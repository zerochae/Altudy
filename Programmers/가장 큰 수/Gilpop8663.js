/* get input */
let numbers = [3, 30, 34, 5, 9];
/* get input end */

/* solve */
// function solution(numbers) {
//   var answer = "";
//   const n = numbers.length;
//   let ch = Array.from({ length: n }, () => 0);
//   function DFS(L, str) {
//     if (L === n) {
//       answer = Math.max(+answer, +str).toString();
//     } else {
//       for (let i = 0; i < n; i++) {
//         if (ch[i] === 0) {
//           ch[i] = 1;
//           DFS(L + 1, str + numbers[i].toString());
//           ch[i] = 0;
//         }
//       }
//     }
//   }
//   DFS(0, "");
//   return answer;
// }
// function solution(numbers) {
//   var answer = "";
//   const n = numbers.length;
//   //   numbers.map((item, i) => {
//   //       console.log(item)}
//   //     // let newA = item.toString();
//   //     // let newB = numbers[i + 1].toString();
//   //     // let isWho = false;
//   //     // let abLength = Math.min(newA.length, newB.length);
//   //     // for (let i = 0; i < abLength; i++) {
//   //     //   if (newA[i] > newB[i]) {
//   //     //     numbers[i + 1] = numbers[i];
//   //     //     return numbers[i + 1];
//   //     //   } else if (newA[i] < newB[i]) return newA[i] - newB[i];
//   //     //   else if (newA[i] === newB[i]) return newA[i] - newB[i - 1];
//   //       //   else if (newA[i] === newB[i]) {
//   //       //     if (newA.length > newB.length) {
//   //       //       if (newA[i] > newB[i - 1]) return newB[i - 1] - newA[i];
//   //       //       else if (newA[i] < newB[i - 1]) return newA[i] - newB[i - 1];
//   //       //     } else if (newA.length < newB.length) {
//   //       //       if (newB[i] > newA[i - 1]) return newA[i - 1] - newB[i];
//   //       //       else if (newB[i] < newA[i - 1]) return newA[i - 1] - newB[i];
//   //       //     } else if (newA.length === newB.length) return newA[i];
//   //       //   }
//   //     // }
//   // //   });
//   //   //   b.toString()[i] - a.toString()[i]
//   numbers = numbers
//     .map((item) => item.toString().split(""))
//     .sort((a, b) => {
//       let abLength = Math.max(a.length, b.length);
//       let aPrevStr;
//       let bPrevStr;
//       for (let i = 0; i < abLength; i++) {
//         // console.log(a[i], b[i]);
//         // console.log(a[a.length - 1]);
//         if (+a[a.length - 1] === 0) return -500;
//         if (+a[i] > +b[i]) return +a[i] - +b[i];
//         else if (+a[i] < +b[i]) return +b[i] - +a[i];
//         else {
//           let aResult = 10 - a[i];
//           let bResult = 10 - b[i];
//           //   console.log(isNaN(aResult), isNaN(bResult));
//           if (isNaN(aResult)) {
//             if (aPrevStr > bResult) return bResult - aPrevStr;
//             // else return b[i] - a[i - 1];
//           }
//           if (isNaN(bResult)) {
//             if (bPrevStr > aResult) return aResult - bPrevStr;
//             // else return b[i - 1] - a[i];
//           }
//           aPrevStr = aResult;
//           bPrevStr = bResult;
//         }
//       }
//     });
//   //   console.log(numbers);
//   answer = numbers
//     .reverse()
//     .map((item) => item.join(""))
//     .join("");
//   return answer;
// }
function solution(numbers) {
  var answer = "";
  //   console.log(numbers.sort(sortFunc));
  numbers.sort(sortFunc);
  answer = numbers.join("");
  if (answer[0] === "0") return "0";
  return answer;
}
const sortFunc = (a, b) => {
  //   console.log(a.toString() + b.toString());
  //   console.log(b.toString() + a.toString());

  const compareA = parseInt(a.toString() + b.toString());
  const compareB = parseInt(b.toString() + a.toString());
  //   console.log(compareA, compareB);
  return compareB - compareA;
};

/* solve end */

/* print output */
console.log(solution(numbers));
/* print output end */
