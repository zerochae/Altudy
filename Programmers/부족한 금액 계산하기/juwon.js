const price = 3, money = 20, count = 4, result = 10

const solution = (price, money, count) => {
    let sum = 0;
    for (let i = 1; i <= count; i++) { 
        sum += price * i
    }
    return sum > money ? sum - money : 0
}

console.log(solution(price, money, count))
