const numbers = [2,1,3,4,1]

const solution = (numbers) => {
    const res = []
    // const set = new Set
    for(let i = 0; i < numbers.length - 1; i++){
        for(let j = i + 1; j< numbers.length; j++){
            const temp = numbers[i] + numbers[j]
            if( res.indexOf(temp) < 0) res.push(temp)
            // set.add(temp)
        }
    }
    return res.sort( (a, b) => a - b)
    // return Array.from(set).sort( (a, b) => a - b)
}

const output = solution(numbers)

console.log(output)
