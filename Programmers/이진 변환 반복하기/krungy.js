/* get input */
const s = "110010101001"; // output =	[3, 8]
// const s = "01110"; // output =	[3, 3]
// const s = "1111111"; // output =	[4, 1]
/* get input end */

/* solve */
function solution(s) {
  let currentStr = s;
  let zeroCount = 0;
  let convertCount = 0;
  while (true) {
    let removeZero = currentStr.match(/1/g).join("");
    zeroCount += currentStr.length - removeZero.length;
    currentStr = removeZero.length.toString(2);
    convertCount++;

    if (currentStr === "1") {
      break;
    }
  }
  return [convertCount, zeroCount];
}

// https://programmers.co.kr/learn/courses/30/lessons/70129

/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
