const arr = [
'3 10',
'10 11 13'
]

const temp1 = arr[0].split(" ")
const temp2 = arr[1].split(" ")

const solution = (arr, arr2) => {
    let start = arr[1]
    let tmp = 0
    for (let i = 0; i < arr[0]; i++) { 
        if ((+start + i) < arr2[i]) { 
            break
        }
        tmp = i + 1
    }
    return +start + tmp
}

console.log(solution(temp1, temp2))
