/* get input */
const board = [
  [0, 0, 0, 0, 0],
  [0, 0, 1, 0, 3],
  [0, 2, 5, 0, 1],
  [4, 2, 4, 4, 2],
  [3, 5, 1, 3, 1],
];
const moves = [1, 5, 3, 5, 1, 2, 1, 4];
/* get input end */

/* set param */
let result = 0;
const stack = [];
/* set param end */

/* solve */
const solution = (board, moves) => {
  moves.map((el) => {
    for (let index in board) {
      if (board[index][el - 1] !== 0) {
        stack.push(board[index][el - 1]);
        board[index][el - 1] = 0;
        break;
      }
    }
  });

  while (true) {
    let flag = result;
    stack.map((el, index) => {
      if (stack[index + 1] && stack[index + 1] === el) {
        stack.splice(index + 1, 1);
        stack.splice(index, 1);
        result++;
      }
    });
    if (flag === result) break;
  }

  return result * 2;
};
/* solve end */

/* print output */
const output = solution(board, moves);
console.log(output);
/* print output end */
