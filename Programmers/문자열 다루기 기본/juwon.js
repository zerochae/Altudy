const solution = ( s = "a234") => { 
    return (s.length === 4 || s.length === 6) && s == parseInt(s)
}

console.log(solution)