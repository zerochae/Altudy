const arr = [3,7]

const solution = (start, end, n, k) => {
    const mid = Math.floor((start + end) / 2);
    const smaller = check(mid, n);
    
    if (start >= end) return mid;
    
    if (smaller < k) return solution(mid + 1, end, n, k);

    return solution(start, mid, n, k);
}

const check = (target, n) => {
    let count = 0;
    
    for (let i = 1; i <= n; i++) {
        count += Math.min(n, parseInt(target / i));
    }
    
    return count;
}
    
console.log(solution(1, arr[0] * arr[0], arr[0], arr[1]))
