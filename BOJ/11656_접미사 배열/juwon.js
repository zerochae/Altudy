const input = 'baekjoon'

const solution = ( input ) => { 
    const stack = [...input]
    const res = []
    const temp = []
    for (let i = 0; i < input.length; i++) { 
        temp.unshift(stack.pop())
        res.push(temp.join(''))
    }
    return res.sort()
}

const output = solution(input)
console.log(output)
