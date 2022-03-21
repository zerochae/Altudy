function solution(numbers) {
  var answer = -1;
  let totalNumbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
  numbers.map(item => {
    for (let i = 0; i < 9; i++) {
      if (item === totalNumbers[i]) {
        totalNumbers.splice(i, 1);
        break;
      }
    }
  });
  answer = totalNumbers.reduce((a, b) => a + b, 0);
  return answer;
}

console.log(solution([1, 2, 3, 4, 7, 8, 0]));
