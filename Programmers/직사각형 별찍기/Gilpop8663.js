/* get input */
let n = 5;
let m = 3;
/* get input end */

/* solve */
process.stdin.setEncoding("utf8");
process.stdin.on("data", (data) => {
  const n = data.split(" ");
  const a = Number(n[0]),
    b = Number(n[1]);
  function solution(a, b) {
    var answer = "";
    const horizon = Array.from({ length: a }).fill("*").join("");
    for (let i = 0; i < b; i++) {
      answer += horizon + "\n";
    }
    return answer;
  }
  console.log(solution(a, b));
});
/* solve end */

/* print output */
console.log(solution(n, m));
/* print output end */
