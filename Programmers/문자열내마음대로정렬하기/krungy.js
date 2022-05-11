/* get input */
const strings = ["sun", "bed", "car"];
const n = 1; // output = ["car", "bed", "sun"]

// const strings = ["abce", "abcd", "cdx"];
// const n = 2; // output = ["abcd", "abce", "cdx"]
/* get input end */

/* solve */
function solution(strings, n) {
  let answer = strings.sort((a, b) => {
    if (a[n] > b[n]) return 1;
    else if (a[n] < b[n]) return -1;
    else if (a[n] == b[n]) {
      if (a > b) return 1;
      else return -1;
    }
  });

  return answer;
}
/* solve end */

/* print output */
const output = solution(strings, n);
console.log(output);
/* print output end */
