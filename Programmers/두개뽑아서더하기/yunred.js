function solution(numbers) {
  var answer = [];
  let tmpArr = Array.from({ length: 2 }, () => 0);
  let tmpNum;
  function DFS(L, S) {
    if (L === 2) {
      tmpNum = tmpArr.reduce((a, b) => a + b);
      answer.push(tmpNum);
    } else {
      for (let i = S; i < numbers.length; i++) {
        tmpArr[L] = numbers[i];
        DFS(L + 1, i + 1);
      }
    }
  }
  DFS(0, 0);
  answer = [...new Set(answer)].sort((a, b) => a - b);
  return answer;
}

console.log(solution([2, 1, 3, 4, 1]));
