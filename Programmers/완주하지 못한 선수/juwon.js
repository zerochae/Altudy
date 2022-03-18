const arr = ["leo", "kiki", "eden"]
const complete = ["eden", "kiki"]

const solution = (arr, complete) => {
    const temp = []
    arr.forEach(el => {
        temp[el] = temp[el] ? temp[el] + 1 : 1
    });
    complete.forEach(el => {
        temp[el] = temp[el] - 1
    });
    for (let key in temp) { 
        if (temp[key] >= 1) { 
            return key
        }
    }
}

console.log(solution(arr, complete))
