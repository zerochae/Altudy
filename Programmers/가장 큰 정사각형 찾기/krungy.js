/* get input */
const board = [
  [0, 1, 1, 1],
  [1, 1, 1, 1],
  [1, 1, 1, 1],
  [0, 0, 1, 0],
]; // output = 9
// const people = [[0, 0, 1, 1], [1, 1, 1, 1]]; // output = 4
/* get input end */

/* solve */
function solution(board) {
  var answer = 0;
  let row = board.length;
  let col = board[0].length;

  if (col <= 1 || row <= 1) {
    return 1;
  }
  for (let i = 1; i < row; i++) {
    for (let j = 1; j < col; j++) {
      if (board[i][j] > 0) {
        let x = board[i][j - 1];
        let y = board[i - 1][j];
        let crs = board[i - 1][j - 1];
        board[i][j] = Math.min(x, y, crs) + board[i][j];
        answer = Math.max(board[i][j], answer);
      }
    }
  }
  return answer * answer;
}
/* solve end */

/* print output */
const output = solution(board);
console.log(output);
/* print output end */
