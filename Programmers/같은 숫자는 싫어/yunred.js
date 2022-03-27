function solution(arr) {
  var answer = [arr[0]];
  for (let i = 1; i < arr.length; i++) {
    if (answer[answer.length - 1] !== arr[i]) answer.push(arr[i]);
  }
  return answer;
}

console.log(solution([1, 1, 3, 3, 0, 1, 1], [1, 3, 0, 1]));
