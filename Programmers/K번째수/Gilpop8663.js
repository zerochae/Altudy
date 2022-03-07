/* get input */
const array = [1, 5, 2, 6, 3, 7, 4];
const commands = [
  [2, 5, 3],
  [4, 4, 1],
  [1, 7, 3],
];
/* get input end */

/* solve */
const solution = (array, commands) => {
  var answer = [];
  console.log(array, commands);
  for (let i = 0; i < commands.length; i++) {
    let newArr = [...array.slice(commands[i][0] - 1, commands[i][1])].sort(
      (a, b) => a - b
    );
    answer.push(newArr[commands[i][2] - 1]);
  }
  return answer;
};
/* solve end */

/* print output */
const output = solution(array, commands);
console.log(output);
/* print output end */
