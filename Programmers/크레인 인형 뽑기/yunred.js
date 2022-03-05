function solution(board, moves) {
  var answer = 0;
  let tmp = [];
  for (let i of moves) {
    for (let j = 0; j < board.length; j++) {
      if (board[j][i - 1] !== 0) {
        if (tmp.length > 1 && tmp[tmp.length - 1] === board[j][i - 1]) {
          answer += 2;
          tmp.pop();
        } else tmp.push(board[j][i - 1]);
        board[j][i - 1] = 0;
        break;
      }
    }
  }
  return answer;
}

console.log(
  solution(
    [
      [0, 0, 0, 0, 0],
      [0, 0, 1, 0, 3],
      [0, 2, 5, 0, 1],
      [4, 2, 4, 4, 2],
      [3, 5, 1, 3, 1],
    ],
    [1, 5, 3, 5, 1, 2, 1, 4]
  )
);
