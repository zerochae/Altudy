const solution = (phone_number = "01033334444") => {
    return "*".repeat(phone_number.length-4) + phone_number.slice(-4)
}
console.log(solution())



