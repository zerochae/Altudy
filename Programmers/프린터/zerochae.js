/* get input */
const priorities = [1, 1, 1];
const location = 1;
/* get input end */

/* solve */
const solution = (priorities, location) => {

  let result = 1;
  
  while (priorities.length !== 0) {
    const target = priorities[location];
    const item = priorities.shift();
    const max = priorities.reduce((result, priority) => {
      return (result = Math.max(result, priority));
    }, target);

    if (max === target && location === 0) break;

    max > item ? priorities.push(item) : result++;

    location = location === 0 ? priorities.length - 1 : location - 1;
  }

  return result;
};
/* solve end */

/* print output */
const output = solution(priorities, location);
console.log(output);
/* print output end */
