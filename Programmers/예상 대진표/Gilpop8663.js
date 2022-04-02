/* get input */
const N = 16;
const A = 9;
const B = 15;
/* get input end */

/* solve */
function solution(n, a, b) {
  var answer = 0;
  let numA = a;
  let numB = b;
  let index = 0;
  while (index < n) {
    index++;
    if (Math.abs(numB - numA) === 1) {
      if (numA > numB && numA % 2 === 0 && numB % 2 === 1) return index;
      else if (numA < numB && numB % 2 === 0 && numA % 2 === 1) return index;
    }
    numA = Math.ceil(numA / 2);
    numB = Math.ceil(numB / 2);
    console.log(numA, numB);
  }
  // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

  return answer;
}
// function solution(n, a, b) {
//   var answer = 0;
//   let numA = a;
//   let numB = b;
//   let index = 0;
//   while (numA !== numB) {
//     numA = Math.ceil(numA / 2);
//     numB = Math.ceil(numB / 2);
//     console.log(numA, numB);
//     answer++;
//   }
//   // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

//   return answer;
// }
// function solution(n, a, b) {
//   var answer = 0;
//   let arr = [];
//   // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
//   let s = Array.from({ length: n }, (v, i) => {
//     return { value: i + 1 };
//   });
//   let index = 0;
//   let prev, next;
//   while (prev === a && next === b ? false : true) {
//     arr = [];
//     index++;
//     for (let i = 0; i < s.length; i = i + 2) {
//       prev = s[i].value;
//       next = s[i + 1].value;
//       //   console.log(index);
//       if (a === s[i].value && b === s[i + 1].value) {
//         answer = index;
//         break;
//       }
//       if (a === s[i].value || b === s[i].value) {
//         arr.push(s[i]);
//       } else if (a === s[i + 1].value || b === s[i + 1].value) {
//         arr.push(s[i + 1]);
//       } else {
//         arr.push(s[i]);
//       }
//     }
//     s = [...arr];
//   }

//   return answer;
// }
/* solve end */

/* print output */
console.log(solution(N, A, B));
/* print output end */
