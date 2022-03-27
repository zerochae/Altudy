const arr = [1,1,3,3,0,1,1]

const solution = (arr) => {
    return arr.filter((v, i) => { return v != arr[i + 1] })
}

console.log(solution(arr))
