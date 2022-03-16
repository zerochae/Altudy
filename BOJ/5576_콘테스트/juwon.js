const arr = [23,23,20,15,15,14,13,9,7,6,25,19,17,17,16,13,12,11,9,5]

const solution = (arr) => {
    const coll1 = []
    const coll2 = []
    for (let i = 0; i < arr.length; i++) { 
        if (coll1.length < 10) {
            coll1.push(arr[i])
        } else { 
            coll2.push(arr[i])
        }
        if (i === arr.length - 1) { 
            coll1.sort( (a, b) => a - b)
            coll2.sort( (a, b) => a - b)
        }
    }
    return `${coll1[coll1.length - 1]+coll1[coll1.length - 2]+coll1[coll1.length - 3]} ${coll2[coll2.length - 1]+coll2[coll2.length - 2]+coll2[coll2.length - 3]}`
}
 
console.log(solution(arr))