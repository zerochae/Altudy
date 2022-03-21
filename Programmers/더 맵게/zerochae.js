/* get input */
const scoville = [1, 2, 3, 9, 10, 12];
const K = 7;
/* get input end */

/* solve */
let count = 0;

const solution = (scoville, K) => {
  return Math.min(...scoville) < K ? recur(scoville) : count;
};

const recur = (scoville) => {
  scoville.push(
    Number(
      scoville.splice(scoville.indexOf(Math.min(...scoville)), 1).pop() +
        scoville.splice(scoville.indexOf(Math.min(...scoville)), 1).pop() * 2
    )
  );
  count++;

  return solution(scoville, K);
};
/* solve end */

/* print output */
const output = solution(scoville, K);
console.log(output);
/* print output end */
