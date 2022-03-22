/* get input */
const s="AB";
let n=1;
/* get input end */

/* solve */
function solution(s, n) {
    var answer = '';

    for(let i=0;i<s.length;i++){
        if(s[i] ===" ") answer +=" "
        else{
            let strNum = s[i].charCodeAt() + n
            answer += String.fromCharCode(strNum)

        }
    }
    return answer;
}
/* solve end */

/* print output */
console.log(solution(s, n))
/* print output end */