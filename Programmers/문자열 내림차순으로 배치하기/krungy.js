/* get input */
const s = "Zbcdefg"; // output = "gfedcbZ"
// const s = "aaaabbbbbc"; // output = "cbbbbbaaaa"
// const s = "ZXCbcdefg"; // output = "gfedcbZXC"
/* get input end */

/* solve */
function solution(s) {
  var answer = "";
  let arr = s.split("");

  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length - i; j++) {
      if (arr[j] <= arr[j + 1]) {
        let tmp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = tmp;
      }
    }
  }
  answer = arr.join("");
  return answer;
}
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
