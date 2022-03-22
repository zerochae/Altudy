/* get input */
const s="0000";
/* get input end */

/* solve */
function solution(s) {
    var answer = true;
    if(isNaN( s.includes("e") ? Number("a") : +s)|| !(s.length === 4 || s.length ===6)) answer=false;
    return answer;
}
/* solve end */

/* print output */
console.log(solution(s))
/* print output end */