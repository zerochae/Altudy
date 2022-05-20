function solution(a, b) {
  var answer = 0;
  let s = a >= b ? b : a;
  let l = a >= b ? a : b;
  for (let i = s; i <= l; i++) {
    answer += i;
  }
  return answer;
}

console.log(solution(3, 5));
