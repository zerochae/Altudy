const solution = (n = 12) => {
    let temp = (n + "").split("").reduce((a, b) => +a + +b)
    return n % temp === 0 ? true : false
}
    
console.log(solution())



