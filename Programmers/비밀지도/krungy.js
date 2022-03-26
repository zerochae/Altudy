/* get input */
const n = 5;
const arr1 = [9, 20, 28, 18, 11];
const arr2 = [30, 1, 21, 17, 28]; // output = ["#####", "# # #", "### #", "#  ##", "#####"]

// const n = 6;
// const arr1 = [46, 33, 33, 22, 31, 50]
// const arr2 = [27, 56, 19, 14, 14, 10] // output = ["######", "###  #", "##  ##", " #### ", " #####", "### # "]
/* get input end */

/* solve */
function solution(n, arr1, arr2) {
  var answer = [];
  for (let i = 0; i < n; i++) {
    let converted = "";
    let arr1Item = arr1[i].toString(2) + "";
    let arr2Item = arr2[i].toString(2) + "";
    while (arr1Item.length !== n || arr2Item.length !== n) {
      if (arr1Item.length < n) {
        arr1Item = "0" + arr1Item;
      }
      if (arr2Item.length < n) {
        arr2Item = "0" + arr2Item;
      }
    }
    for (let j = 0; j < n; j++) {
      arr1Item[j] === "1" || arr2Item[j] === "1"
        ? (converted += "#")
        : (converted += " ");
    }
    answer.push(converted);
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(n, arr1, arr2);
console.log(output);
/* print output end */
