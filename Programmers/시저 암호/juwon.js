const temp = "a B z"

const solution = (s, n = 4) => {
    return s.split("").map(el => { 
        if (el === " ") return el;
        return el.toUpperCase().charCodeAt() + n > 90 ? String.fromCharCode(el.charCodeAt() + n - 26) : String.fromCharCode(el.charCodeAt() + n)
    }).join("")
}

console.log(solution(temp))
