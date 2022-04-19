const solution = ( n = 10) => { 
    let res = 0;
    for(let i = 2; i <= n; i++){
        let cnt = 0;
        for (let j = 2; j <= i; j++){
            if(i % j === 0) cnt++;
        }
        if(cnt < 2){
            res++;
        }
     }
    return res;
}

console.log(solution())
