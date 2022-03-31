/* get input */
let s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
/* get input end */

/* solve */
function solution(s) {
  var answer = [];
  //   let newArr = JSON.parse(s.replace(/{/g, "[").replace(/}/g, "]"));
  //   console.log(newArr);
  s = s
    .replace(/[}]/gi, "")
    .slice(2)
    .split("{")
    .map((item) => {
      if (item.slice(-1) === ",") {
        return item.slice(0, -1).split(",");
      } else {
        return item.split(",");
      }
    })
    .sort((a, b) => a.length - b.length);
  //   console.log(s);
  for (let i = 0; i < s.length; i++) {
    for (let j = 0; j < s[i].length; j++) {
      if (answer.indexOf(+s[i][j]) === -1) {
        answer.push(+s[i][j]);
      }
    }
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(s));
/* print output end */
