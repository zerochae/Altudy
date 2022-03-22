/* get input */
const strings=["abce", "abcd", "cdx"];
const n=2;
/* get input end */

/* solve */
function solution(strings, n) {
    var answer = [];
    strings.sort()
    answer = strings.sort((a,b)=>{
        return +a.charCodeAt(n)-+b.charCodeAt(n)})
    return answer;
}
/* solve end */

/* print output */
console.log(solution(strings, n))
/* print output end */