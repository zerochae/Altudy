function solution(a, b) {
  var answer = '';
  let week = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT'];
  let month = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  let day = b;
  for (let i = 0; i < a - 1; i++) {
    day += month[i];
  }
  let dayIndex = (day + 4) % 7;
  answer = week[dayIndex];
  return answer;
}

console.log(solution(5, 24));
