/* get input */
const citations = [3, 0, 6, 1, 5]; // output = 3
/* get input end */

/* solve */
function solution(citations) {
  var answer = 0;
  let i = 0;
  let arr = citations.sort((a, b) => b - a);

  while (i + 1 <= arr[i]) {
    i++;
  }
  answer = i;
  return answer;
}
/* solve end */

/* print output */
const output = solution(citations);
console.log(output);
/* print output end */
