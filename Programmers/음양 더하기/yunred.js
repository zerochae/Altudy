function solution(absolutes, signs) {
  var answer = 123456789;
  answer = 0;
  absolutes.forEach((el, idx) => {
    signs[idx] ? (answer += el) : (answer -= el);
  });
  return answer;
}

console.log(solution([4, 7, 12], [true, false, true]));
