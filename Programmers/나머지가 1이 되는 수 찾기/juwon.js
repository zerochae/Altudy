const n = 10

const solution = (n, x = 1) => {
    // 1
    while(x++){
        if ( n % x === 1) return x;
    }
    // 2
    for(i = x + 2; i < n; i ++){
        if( n % i === 1) return i;
    }
}

const output = solution(n)
console.log(output)
