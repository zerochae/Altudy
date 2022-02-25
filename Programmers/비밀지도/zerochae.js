/* get input */
let n = 6;
arr1 = [46, 33, 33, 22, 31, 50];
arr2 = [27, 56, 19, 14, 14, 10];
/* get input end */

/* solve */
const solution = (n, arr1, arr2) => {

  return new Array(n).fill(null).map((row, index) => {
    return (arr1[index] | arr2[index])
      .toString(2)
      .padStart(n, 0)
      .replace(/1/g, "#")
      .replace(/0/g, " ");
  });
};
/* solve end */

/* print output */
const output = solution(n, arr1, arr2);
console.log(output);
/* print output end */
