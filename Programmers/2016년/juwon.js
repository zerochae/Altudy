const a = 5
const b = 24

const solution = (a, b) => {
    const day = ["THU","FRI","SAT","SUN","MON","TUE","WED"]
    const month = [31,29,31,30,31,30,31,31,30,31,30,31]
    const year = 2016
    let sum = 0

    if(year % 4 !== 0) month[1] = 28
    
    for (let i = 0; i < a - 1; i++) { 
        sum += month[i]
    }
    sum += b
    return day[sum % 7]
}

const sol2 = (a, b) => {
    const day = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
    const date = new Date(`${a}, ${b}, 2016`).getDay()
    return day[date]
}

console.log(sol2(a, b))

