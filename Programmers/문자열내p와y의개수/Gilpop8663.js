/* get input */
let s="pPoooyY"
/* get input end */

/* solve */
function solution(s){
    var answer = true;
    let pCount=0;
    let yCount=0;

     s.toLowerCase().split("").forEach(item=>{
        if(item === "p") pCount++
        else if(item ==="y") yCount++
    })
console.log(pCount,yCount)
answer = pCount === yCount ? true : false
    return answer;
}
/* solve end */

/* print output */
console.log(solution(s))
/* print output end */