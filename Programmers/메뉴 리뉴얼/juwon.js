// const orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
const orders = ["XYZ", "XWY", "WXA"]
const courses = [2,3,4]

const solution = (orders, courses) => {
    var answer = [];


    for (const course of courses) {

        let map = new Map
        
        // for(const order of orders){
        // orders.map( (el) => {
        //     map = combieCourse(el, "", course, 0, 0, map)
        // } )    
        // }
        
        orders.map( (el) => {
            map = combieCourse(el, "", course, 0, 0, map)
        })
        

        let max = -1
        
        for(let value of map.keys()){
            max = Math.max(map.get(value), max)
        }

        for(let value of map.keys()){
            if(map.get(value) >= 2){
                if(max == map.get(value)){
                    answer.push(value)
                }
            }
        }
    }

    return answer.sort();
}

const combieCourse = (order, res, max, level, start, map) => {
    if (level === max){
        res = res.split("")
        res = res.sort().join("")
        map.set(res, map.get(res) === undefined ? 1 : map.get(res) + 1)
    }else{
        for(let i = start; i < order.length; i++){
            const temp = order.split("")
            combieCourse(order, res + temp[i], max, level + 1, i + 1, map)
        }

    }
    
    return map
}
const output = solution(orders, courses)

console.log(output)
