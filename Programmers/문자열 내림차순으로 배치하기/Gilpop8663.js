/* get input */
const s="Zbcdefg";
/* get input end */

/* solve */
function solution(s) {
    var answer = '';
    answer = s.split("").sort((a,b)=>b.charCodeAt()-a.charCodeAt()).join("")
    return answer;
}
/* solve end */

/* print output */
console.log(solution(s))
/* print output end */