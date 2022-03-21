/* get input */
const n = 78; // output = 83
// const n = 15; // output = 23

/* get input end */

/* solve */
function solution(n) {
  var answer = 0;
  const nBinaryCountOne = (n.toString(2) + "")
    .match(/1/g)
    .filter((value) => value !== "").length;
  let findNum = n + 1;

  while (true) {
    let findBinaryCountOne = (findNum.toString(2) + "")
      .match(/1/g)
      .filter((value) => value !== "").length;
    if (nBinaryCountOne === findBinaryCountOne) {
      answer = findNum;
      break;
    }
    findNum++;
  }

  return answer;
}
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
