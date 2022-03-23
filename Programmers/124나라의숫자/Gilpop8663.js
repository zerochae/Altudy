/* get input */
let n = 2;
/* get input end */

/* solve */
function solution(n) {
  var answer = "";
  let numberArr = [4, 1, 2];
  while (n > 0) {
    let remain = n % 3;
    answer = numberArr[remain] + answer;
    if (remain === 0) {
      n = Math.floor(n / 3) - 1;
    } else {
      n = Math.floor(n / 3);
    }
  }
  return answer;
}
/* solve end */

/* print output */
for (let i = 1; i <= 100; i++) {
  console.log(solution(i), i);
}
/* print output end */

/*
1 1 1 1
2 2 2 2
4 3 3 10
11 4 4 11
12 5 11 12
14 6 12 20
21 7 13 21
22 8 20 22
24 9 21 30
41 10 22 
42 11 23
44 12 30
111 13 31
*/
