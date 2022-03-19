const arr = ["sun", "bed", "car"]
const n = 1
const solution = (arr, n) => {
    let temp = arr.sort((a, b) => { 
        if (a[n] > b[n]) return 1
        if (a[n] < b[n]) return -1
        if (a[n] === b[n]) { 
            if (a > b) return 1
            if (a < b) return -1
            return 0
        }
    })
    return temp
}

const solution2 = (arr, n) => { 
    return arr.map( a => [...a][n]+a).sort().map( a=> a.substring(n))
}

console.log(solution2(arr, n))
