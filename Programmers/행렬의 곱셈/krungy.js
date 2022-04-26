/* get input */
const arr1 = [
  [1, 4],
  [3, 2],
  [4, 1],
];
const arr2 = [
  [3, 3],
  [3, 3],
]; // output = [[15, 15], [15, 15], [15, 15]]

// const arr1 = [
//   [2, 3, 2],
//   [4, 2, 4],
//   [3, 1, 4],
// ];
// const arr2 = [
//   [5, 4, 3],
//   [2, 4, 1],
//   [3, 1, 1],
// ]; // output = [[22, 22, 11], [36, 28, 18], [29, 20, 14]]
/* get input end */

/* solve */
function solution(arr1, arr2) {
  var answer = [];

  for (let i = 0; i < arr1.length; i++) {
    let tmp = [];
    for (let j = 0; j < arr2[0].length; j++) {
      let sum = 0;
      for (let k = 0; k < arr1[i].length; k++) {
        sum += arr1[i][k] * arr2[k][j];
      }
      tmp.push(sum);
    }
    answer.push(tmp);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(arr1, arr2);
console.log(output);
/* print output end */
