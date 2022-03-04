/* get input */
const board = [
  [0, 0, 0, 0, 0],
  [0, 0, 1, 0, 3],
  [0, 2, 5, 0, 1],
  [4, 2, 4, 4, 2],
  [3, 5, 1, 3, 1],
];
const moves = [1, 1, 5];

/* get input end */

/* solve */
function solution(board, moves) {
  let stack = [];
  let lastUnit;
  var answer = 0;

  moves.forEach((item, index) => {
    for (let i = 0; i < board.length; i++) {
      if (board[i][item - 1] !== 0) {
        lastUnit = board[i][item - 1];
        if (lastUnit === stack[stack.length - 1]) {
          stack.pop();
          answer += 2;
        } else {
          stack.push(board[i][item - 1]);
        }
        board[i][item - 1] = 0;
        break;
      }
    }
  });

  return answer;
}
/* solve end */

/* print output */
console.log(solution(board, moves));
/* print output end */
