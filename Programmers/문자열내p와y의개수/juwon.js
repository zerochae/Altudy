const arr = 'Pyy'

const solution = (arr) => {
    let p = 0, y = 0
    arr.split('').map(el => {
        if (el === 'p' | el === 'P') p++
        else if (el === 'y' | el === 'Y') y++
    })
    return p === y
}
const solution2 = (arr) => { 
    return arr.toUpperCase().split("P").length === arr.toUpperCase().split("Y").length
}

console.log(solution2(arr))
