/* get input */
let name = "BBBBAA";
/* get input end */

/* solve */
function solution(name) {
  var answer = 0;
  let n = name.length;
  let strArr = Array.from({ length: 26 }, (v = 65, i) => {
    return String.fromCharCode(v + i);
  });
  let index = 0;
  let move = n - 1;
  for (let i = 0; i < n; i++) {
    // console.log(
    //   name[i].charCodeAt() - "A".charCodeAt(),
    //   "Z".charCodeAt() - name[i].charCodeAt() + 1
    // );
    answer += Math.min(
      name[i].charCodeAt() - "A".charCodeAt(),
      "Z".charCodeAt() - name[i].charCodeAt() + 1
    );
    index = i + 1;
    // console.log(index);
    while (index < n && name[index].charCodeAt() === "A".charCodeAt()) {
      index++;
    }
    // console.log(index);n
    // console.log(i, index, n, i * 2 + n - index, move, (n - index) * 2 + i);
    move = Math.min(move, i * 2 + n - index);
    move = Math.min(move, (n - index) * 2 + i);
  }
  return answer + move;
}
/* solve end */

/* print output */
console.log(solution(name));
/* print output end */
