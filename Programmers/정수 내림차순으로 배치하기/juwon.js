const solution = (n = 118372) => {
    return +((n+"").split("").sort().reverse().join(""))
}

console.log(solution())




