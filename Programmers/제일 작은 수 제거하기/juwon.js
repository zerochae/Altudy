const solution = (arr = [4, 3, 2, 1]) => {
    arr.splice(arr.indexOf(Math.min(...arr)), 1)
    return arr.length ? arr : [-1]
}

console.log(solution())



