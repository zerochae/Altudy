const solution = (n = 121) => {
    let temp = Math.sqrt(n)
    return temp % 1 === 0 ? (temp + 1) * ( temp + 1): -1
}

console.log(solution())
