/* get input */
const arr=[3,2,6]
const divisor=10;
/* get input end */

/* solve */
function solution(arr, divisor) {
    var answer = [];
    arr.forEach((item)=>{
        if(item % divisor === 0) answer.push(item)
    })
    if(answer.length ===0) answer.push(-1)
    answer.sort((a,b)=>a-b)
    return answer;
}
/* solve end */

/* print output */
console.log(solution(arr,divisor))
/* print output end */