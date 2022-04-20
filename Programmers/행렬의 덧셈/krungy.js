/* get input */
const arr1 = [
  [1, 2],
  [2, 3],
];
const arr2 = [
  [3, 4],
  [5, 6],
]; // output = [[4, 6], [7, 9]]

// const arr1 = [[1], [2]];
// const arr2 = [[3], [4]]; // output = [[4], [6]]
/* get input end */
/* solve */
function solution(arr1, arr2) {
  var answer = [];

  for (let i = 0; i < arr1.length; i++) {
    answer[i] = [];
    for (let j = 0; j < arr1[i].length; j++) {
      answer[i].push(arr1[i][j] + arr2[i][j]);
    }
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(arr1, arr2);
console.log(output);
/* print output end */
