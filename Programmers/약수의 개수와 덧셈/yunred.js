function getDivisior(num) {
  let divisiorNum = 0;
  for (let i = 1; i <= Math.sqrt(num); i++) {
    if (num / i === Math.sqrt(num)) divisiorNum++;
    else if (Number.isInteger(num / i)) divisiorNum += 2;
  }
  return divisiorNum;
}

function solution(left, right) {
  var answer = 0;
  for (let i = left; i <= right; i++) {
    let divisor = getDivisior(i);
    divisor % 2 === 0 ? (answer += i) : (answer -= i);
  }
  return answer;
}

console.log(solution(13, 17));
