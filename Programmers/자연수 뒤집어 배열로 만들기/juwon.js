const solution = (n = 12345) => {
    // return (n+"").split("").reverse().map(el => +el);
    // return String(n).split("").reverse().map(el => parseInt(el))
    return n.toString().split("").reverse().map(el => el = Number(el))
}

console.log(solution())
