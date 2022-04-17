const solution = (arr1 = [[1, 2], [2, 3]], arr2 = [[3, 4], [5, 6]]) => {
    return arr1.map((arr1El, arr1Index) => arr1El.map((arr2El, arr2Index) => { return arr2El + arr2[arr1Index][arr2Index]}))
 }

console.log(solution())
