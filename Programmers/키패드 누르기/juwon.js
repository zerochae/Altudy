const solution = (numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], hand = "right") => {
    let res = ""

    const Point = {
        1: [0, 0],
        2: [0, 1],
        3: [0, 2],
        4: [1, 0],
        5: [1, 1],
        6: [1, 2],
        7: [2, 0],
        8: [2, 1],
        9: [2, 2],
        "*": [3, 0],
        0: [3, 1],
        "#": [3, 2],
    }
    
    const distance = (startHand, point) => { 
        let temp = 0;
        temp += Math.max(startHand[0], point[0]) - Math.min(startHand[0], point[0])
        temp += Math.max(startHand[1], point[1]) - Math.min(startHand[1], point[1])
        return temp
    } 
    
    let rightHand = Point['#']
    let leftHand = Point['*']

    for (let i = 0; i < numbers.length; i++) { 
        let right = false
        const target = numbers[i]
        if (target === 1 || target === 4 || target === 7) {
        }
        else if (target === 3 || target === 6 || target === 9) {
            right = true
        } else { 
            
            const leftDistance = distance(leftHand, Point[target]);
            const rightDistance = distance(rightHand, Point[target]);
            
            if (leftDistance === rightDistance) {
                if (hand === "right") {
                    right = true;
                }
            } else if (leftDistance > rightDistance) {
                right = true;
            }

        }

        if (right) {
            rightHand = Point[target]
            res += "R"
        } else { 
            leftHand = Point[target]
            res += "L"
        }
    }

    return res
}
    
console.log(solution())



