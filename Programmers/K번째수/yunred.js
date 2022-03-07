function solution(array, commands) {
  var answer = [];
  let tmpArray = [];

  for (let item of commands) {
    tmpArray = array.slice(item[0] - 1, item[1]).sort((a, b) => a - b);
    answer.push(tmpArray[item[2] - 1]);
    tmpArray = [];
  }
  return answer;
}

console.log(
  solution(
    [1, 5, 2, 6, 3, 7, 4],
    [
      [2, 5, 3],
      [4, 4, 1],
      [1, 7, 3],
    ]
  )
);
