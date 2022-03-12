/* get input */
const n = 7;
const lost = [1, 2, 3, 4, 5];
const reserve = [1, 2, 3, 6];
/* get input end*/

/* solve */
function solution(n, lost, reserve) {
  lost.sort();
  reserve.sort();
  var answer = 0;
  let count = 0;
  let all = Array.from({ length: n }, (_, i) => i + 1);
  let remain = reserve;
  let newLost = [];
  for (let i = 0; i < lost.length; i++) {
    if (remain.includes(lost[i]) === true) {
      const findIndex = (remain.findIndex = remain.findIndex(
        (item) => item === lost[i]
      ));
      remain = [...remain.slice(0, findIndex), ...remain.slice(findIndex + 1)];
    } else {
      const findIndex = all.findIndex((item) => item === lost[i]);
      newArr = [...all.slice(0, findIndex), ...all.slice(findIndex + 1)];
      all = newArr;
      newLost.push(lost[i]);
    }
  }
  remain.sort();
  let firstArr = new Set(all);
  for (let i = 0; i < remain.length; i++) {
    if (newLost.includes(remain[i] + 1) | newLost.includes(remain[i] - 1)) {
      count++;
    }
  }
  answer = firstArr.size + count;
  if (answer > n) {
    answer = n;
  }
  return answer;
}
/* solve end*/

/* print output */
console.log(solution(n, lost, reserve));
/* print output end */
