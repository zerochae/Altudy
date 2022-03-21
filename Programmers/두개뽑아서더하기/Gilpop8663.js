const numbers = [2, 1, 3, 4, 1];

function solution(numbers) {
  var answer = [];
  const arr = new Set();
  for (let i = 0; i < numbers.length; i++) {
    for (let j = i + 1; j < numbers.length; j++) {
      arr.add(numbers[i] + numbers[j]);
    }
  }
  answer = [...arr].sort((a, b) => a - b);
  return answer;
}

console.log(solution(numbers));
