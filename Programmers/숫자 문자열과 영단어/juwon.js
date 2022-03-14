const input = 'one4seveneight'

const solution = (input) => {
    const arr = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    
    let res = input

    for (let i = 0; i < arr.length; i++) { 
        let temp = res.split(arr[i])
        res = temp.join(i)
    }
    
    return +res
}

const output = solution(input)
console.log(output)

