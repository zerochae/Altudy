const solution = (n = 987) => { 
    return (n + "").split("").reduce((a, b) => +a + +b , 0)
}
    
console.log(solution())



