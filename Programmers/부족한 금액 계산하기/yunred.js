function solution(price, money, count) {
  var answer = -1;
  answer = 0;
  for (let i = 1; i <= count; i++) {
    answer += price * i;
  }
  answer = answer > money ? answer - money : 0;
  return answer;
}

console.log(solution(3, 20, 4));
