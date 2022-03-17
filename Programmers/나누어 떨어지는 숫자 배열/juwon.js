const arr = [5, 9, 7, 10]
let divisor = 5

const solution = (arr, divisor) => {
    const temp = []
    arr.map(el => { el % divisor === 0 && temp.push(el) })
    return temp.length ? temp.sort( (a, b)=> a - b ) : [-1]
}   

const solution2 = (arr, divisor) => { 
    const temp = arr.filter(v => v % divisor === 0)
    return temp.length === 0 ? [-1] : temp.sort( (a, b) => a - b)
}
console.log(solution(arr, divisor))
