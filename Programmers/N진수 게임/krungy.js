/* get input */
const n = 2;
const t = 4;
const m = 2;
const p = 1; // output = "0111"

// const n = 16;
// const t = 16;
// const m = 2;
// const p = 1; // output = "02468ACE11111111"

// const n = 16;
// const t = 16;
// const m = 2;
// const p = 2; // output = "13579BDF01234567"
/* get input end */

/* solve */
function solution(n, t, m, p) {
  //n: 진법, t: 출력 숫자 갯수, m: 참가 인원, p: 내 순서
  var answer = "";
  let num = [];

  for (let i = 0; i < t * m; i++) {
    num.push(i.toString(n));
  }
  let numstr = num.join("");
  let cnt = 0;
  for (let i = 0; i < numstr.length; i++) {
    if (i % m == p - 1) {
      answer += numstr[i].toUpperCase();
      cnt++;
      if (cnt == t) break;
    }
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(n, t, m, p);
console.log(output);
/* print output end */
