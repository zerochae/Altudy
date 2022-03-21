const arr = [23,23,20,15,15,14,13,9,7,6,25,19,17,17,16,13,12,11,9,5]

const solution = (arr) => {
    const temp1 = arr.splice(0, 10).sort((a, b) => b - a)
    const temp2 = arr.sort( (a, b) => b - a)
    return `${temp1[0]+temp1[1]+temp1[2]} ${temp2[0]+temp2[1]+temp2[2]}`
}   
 
console.log(solution(arr))