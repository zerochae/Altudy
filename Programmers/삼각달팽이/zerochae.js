/* get input */
const n = 6;
/* get input end */

/* solve */
const solution = (n) => {

  const result = new Array(n)
  .fill(null)
  .map((row, row_index) => new Array(row_index + 1).fill(null));
  
  let num = 0;
  let row = -1;
  let col = 0;

  const recur = (n) => {
    for (let i = 0; i < n; i++) { //down
      row++; num++;
      result[row][col] = num;
    }
    for (let i = 0; i < n - 1; i++) { //right
      col++; num++;
      result[row][col] = num;
    }
    for (let i = 0; i < n - 2; i++) { // up
      row--; col--; num++;
      result[row][col] = num;
    }
  }

  while(n > 0){
    recur(n);
    n-=3;
  }

  return result.reduce((result, arr) => {
        return [...result, ...arr];
      }, []);
};
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end */
