const arr = [5, 9, 7, 10]
let divisor = 5
const solution = (arr, divisor) => {
    const temp = []
    for (let i = 0; i < arr.length; i++) { 
        if (arr[i] % divisor === 0) { 
            temp.push(arr[i])
        }
    }
    if (temp.length === 0) return [-1]
    else { 
        temp.sort( (a, b) => a - b)
        return temp
    }
}   
 
console.log(solution(arr, divisor))
