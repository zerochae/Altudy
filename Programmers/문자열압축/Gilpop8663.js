/* get input */
const s = "aabbaccc";

/* get input end */

/* solve */
function solution(s) {
  var answer = 0;
  console.log(s);
  let str = "";
  let prevStr = "";
  let minStr = "";
  let count = 1;
  //   for (let i = 0; i < s.length; i++) {
  //     if (prevStr === s[i]) {
  //       count++;
  //       if (i === s.length - 1) {
  //         str += `${count === 1 ? "" : count}${prevStr}`;
  //         count = 1;
  //         prevStr = s[i];
  //       }
  //     } else {
  //       str += `${count === 1 ? "" : count}${prevStr}`;
  //       count = 1;
  //       prevStr = s[i];
  //     }
  //     prevStr = s[i];
  //     console.log(prevStr, s[i], count, i, s.length);
  //     console.log(str);
  //   }

  for (let i = 0; i < s.length - 1; i++) {
    for (let j = i + 1; j < s.length; j++) {
      str = "";

      count = 1;
      for (let k = 0; k < s.length; k++) {
        prevStr = s.slice(i, j);
        // console.log(
        //   prevStr,
        //   s.indexOf(prevStr, k + 1),
        //   s.indexOf(prevStr, k),
        //   count
        // );
        console.log(prevStr);
        if (
          s.indexOf(prevStr, k + prevStr.length) - s.indexOf(prevStr, k) ===
          prevStr.length
        ) {
          count++;
          if (
            k === s.length - 1 ||
            s.indexOf(prevStr, k + prevStr.length) === -1
          ) {
            str += `${count === 1 ? "" : count}${prevStr}`;
          }
        } else if (
          s.indexOf(prevStr, k + prevStr.length) === -1 &&
          count !== 1
        ) {
          str += `${count === 1 ? "" : count}${prevStr}`;
          minStr += `${count === 1 ? "" : count}${prevStr}`;
          count = 1;
        } else {
          count = 1;
          str += s[k];
        }
      }
      console.log(str);
      //   console.log(minStr);
    }
  }

  return answer;
}
/* solve end */

/* print output */
console.log(solution(s));
/* print output end */
