/* get input */
let numbers = "1231";

/* get input end */

/* solve */
function solution(numbers) {
  var answer = 0;
  numbers = numbers.split("");
  let n = numbers.length;
  let ch = Array.from({ length: n }, () => 0);
  const set = new Set();
  for (let i = 0; i < n; i++) {
    set.add(+numbers[i]);
  }
  function DFS(L, sum) {
    if (L === n) {
      set.add(+sum);
    } else {
      set.add(+sum);
      for (let i = 0; i < n; i++) {
        if (ch[i] === 0) {
          ch[i] = 1;
          DFS(L + 1, sum + numbers[i]);
          ch[i] = 0;
        }
      }
    }
  }
  DFS(0, "");
  let arr = [...set];
  console.log(arr);
  for (let i = 0; i < set.size; i++) {
    let cnt = 0;

    if (arr[i] < 2) continue;
    for (let j = 2; j <= Math.sqrt(arr[i]); j++) {
      if (arr[i] % j === 0) {
        cnt++;
        break;
      }
    }
    if (cnt === 0) {
      answer++;
    }
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(numbers));
/* print output end */
w