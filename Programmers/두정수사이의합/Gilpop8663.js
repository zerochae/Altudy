/* get input */
const a=3;
const b=5;
/* get input end */

/* solve */
function solution(a, b) {
    var answer = 0;
    let min = a<b ? a : b;
    let max = a>b ? a: b;
    for(let i=min;i<=max;i++){
        answer += i
    }
    return answer;
}
/* solve end */

/* print output */
console.log(solution(a,b))
/* print output end */