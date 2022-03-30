function solution(n) {
  var answer = 0;
  let arr = Array.from({ length: n + 1 }, () => 0);
  arr[0] = 1;
  arr[1] = 1;
  for (let i = 2; i < arr.length; i++) {
    for (let j = i * 2; j < arr.length; j += i) {
      arr[j] = 1;
    }
  }
  answer = arr.filter(number => !number).length;
  return answer;
}

console.log(solution(5));
