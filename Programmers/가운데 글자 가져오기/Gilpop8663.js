const s="abcde";

function solution(s) {
    var answer = '';
    if(s.length %2 === 1){
        return answer = s[Math.floor(s.length/2)]
    }else{
        return answer =s[s.length/2 -1]+s[s.length/2]
    }
}

console.log(solution(s))