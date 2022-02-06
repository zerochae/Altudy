/* get input */
let n = 9;
/* get input end */

/* set param */
let result = "";
/* set param end */

/* solve */
const solution = (n) => {
    result += n % 3 === 0 ? n / Math.floor(n / 3) : n % 3; /*   n / Math.floor(n / 3) === 3  ∴ result += n % 3 === 0 ? "4" (replace("3","4")) : n % 3;  */ 
    n = n % 3 === 0 ? Math.floor(n / 3) - 1 : Math.floor(n / 3);
    
    return n > 0 ? solution(n) : result.split("").reverse().join("").replace(/3/gi, "4");
};
/* solve end */

/* print output */
const output = solution(n);
console.log(output);
/* print output end*/
