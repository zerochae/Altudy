const absolutes = [4,7,12]
const signs = [true,false,true]

function solution(absolutes, signs) {
    return absolutes.reduce( (sum, value, index) => sum += signs[index] ? value : value * -1 , 0 );
}

const output = solution(absolutes, signs)
console.log(output)