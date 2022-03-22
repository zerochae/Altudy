const arr =[4,4,4,3,3];

function solution(arr)
{
    var answer = [];

    arr.forEach((item,i)=>{
        if(item === arr[i+1]) return;
        else answer.push(item)
    })
    return answer;
}

console.log(solution(arr))