const solution = (array = [1, 5, 2, 6, 3, 7, 4], commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]) => {
    let result = []
    for (let i = 0; i < commands.length; i++) { 
        for (let j = 0; j < commands[i].length -2 ; j++) { 
            let temp = commands[i][j]
            let temp2 = commands[i][j + 1]
            let temp3 = commands[i][j + 2]
            let temp4 = array.slice(temp-1, temp2).sort( (a, b) => a - b)
            result.push(temp4[temp3-1])
        }
    }
    return result
}
    
console.log(solution())