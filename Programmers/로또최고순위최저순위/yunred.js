function solution(lottos, win_nums) {
  var answer = [];
  let max = 0;
  let min = 0;
  lottos.forEach(element => {
    if (win_nums.indexOf(element) !== -1) {
      max++;
      min++;
    } else if (element === 0) max++;
  });
  max < 2 ? (max = 1) : max;
  min < 2 ? (min = 1) : min;
  answer = [7 - max, 7 - min];
  return answer;
}

console.log(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]));
