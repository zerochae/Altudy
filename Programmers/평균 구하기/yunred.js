function solution(arr) {
  var answer = 0;
  answer = arr.reduce((a, b) => a + b) / arr.length;
  return answer;
}

console.log(solution([1, 2, 3, 4]));
