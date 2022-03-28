function solution(s) {
  var answer = '';
  if (s.length % 2 === 1) {
    answer = s[parseInt(s.length / 2)];
  } else {
    answer = s.slice(s.length / 2 - 1, s.length / 2 + 1);
  }
  return answer;
}

console.log(solution('qwer'));
