const solution = (n = 4) => {
    let res = ""
    for (let i = 0; i < n; i++) { 
        i % 2 === 0 ? res+= "수" : res+= "박"
    }
    return res
}

console.log(solution())

