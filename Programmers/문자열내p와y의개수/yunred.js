function solution(s) {
  var answer = true;
  let diffNum = 0;
  s = s.toLowerCase();
  for (let x of s) {
    if (x === 'p') diffNum++;
    else if (x === 'y') diffNum--;
  }
  if (diffNum !== 0) answer = false;
  return answer;
}
console.log(solution('pPY'));
