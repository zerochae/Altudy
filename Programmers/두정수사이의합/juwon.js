const arr = [3, 5]

const solution = (arr) => {
    const [a, b] = arr
    let res = 0;
    if (a > b) { 
        let temp = a 
        a = b 
        b = temp
    }
    for (i = a;  i <= b; i++) { 
        res += i
    }
    return res
}

console.log(solution(arr))
