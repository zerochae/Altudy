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
  return commands.map((command) => {
    return [...array].slice(command[0] - 1, command[1]).sort((a, b) => a - b)[
      command[2] - 1
    ];
  });
};
/* solve end */

/* print output */
const output = solution(array, commands);
console.log(output);
/* print output end */
