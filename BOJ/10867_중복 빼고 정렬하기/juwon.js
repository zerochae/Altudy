let input = '10 1 4 2 3 1 4 2 3 1 2'
input = input.split(" ")
input.shift()


const solution = (input) => {
    return [...new Set(input.sort())]
}

const output = solution(input)
console.log(output)

