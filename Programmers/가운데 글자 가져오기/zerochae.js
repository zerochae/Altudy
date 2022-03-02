/* get input */
const s = "qwer";
/* get input end */

/* solve */
const solution = (s) => {
  const str = s.split("");
  const index = Math.floor(s.length / 2);

  return s.length % 2 === 0 ? `${str[index - 1]}${str[index]}` : str[index];
};
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
