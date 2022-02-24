/* get input */
let s = 'one4seveneight';
/* get input end*/

/* set param */
const patterns = ['zero','one','two','three','four','five','six','seven','eight','nine']
/* set param end */

/* solve */
const solution = (s) => {
  return Number(patterns.map((pattern,index) =>{
    return s = s.replace(new RegExp(pattern,"g"),index)
  }).pop())
};
/* solve end*/

/* print output */
const output = solution(s);
console.log(output);
/* print output end*/