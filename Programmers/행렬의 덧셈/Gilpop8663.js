/* get input */
let arr1 = [
  [1, 2, 5],
  [2, 15, 8],
];
let arr2 = [
  [3, 0, 1],
  [4, 5, 8],
];
/* get input end */

/* solve */
function solution(arr1, arr2) {
  var answer = [];
  for (let i = 0; i < arr1.length; i++) {
    let sumArr = [];
    for (let j = 0; j < arr1[i].length; j++) {
      sumArr.push(arr1[i][j] + arr2[i][j]);
    }
    answer.push(sumArr);
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(arr1, arr2));
/* print output end */
