/* get input */
let dartResult="0D*2S*0T"
/* get input end */

/* solve */
function solution(dartResult) {
    var answer = 0;
   dartResult= dartResult.split("");
   let count =1;
   let first=0;
   let second=0;
   let third =0;
   dartResult.forEach((item,i)=>{
       if(count ===1){
           if(+item> 1){
            first = +item               
        }else if(+item ===1){
            if(+dartResult[i+1] !== 0){
                first =1
            }else{
                first =10
            }
        }
        else{
            if(item === "S"){
                first = first
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="D"){
                first = first **2
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="T"){
                first = first **3
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="*"){
                first = first *2
                count ++
            }else if(item ==="#"){
                first = -first
                count ++
            }
        }
       }else if(count ===2){
           if(+item> 1){
               second = +item               
        }else if(+item ===1){
            if(+dartResult[i+1] !== 0){
                second =1
            }else{
                second =10
            }
        }else{
            if(item === "S"){
                second = second
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="D"){
                second = second **2
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="T"){
                second = second **3
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="*"){
                first = first *2
                second = second *2 
                count ++
            }else if(item ==="#"){
                second = -second
                count ++
            }
        }
    }else if(count ===3){
        if(+item> 1){
            third = +item               
        }else if(+item ===1){
            if(+dartResult[i+1] !== 0){
                third =1
            }else{
                third =10
            }
        }else{
            if(item === "S"){
                third = third
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="D"){
                third = third **2
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="T"){
                third = third **3
                if(+dartResult[i+1] >= 0){
                    count ++
                }
            }else if(item ==="*"){
                second = second *2
                third = third *2 
                count ++
            }else if(item ==="#"){
                third = -third
                count ++
            }
       }
    }
})
answer = first + second + third
    return answer;
}
/* solve end */

/* print output */
console.log(solution(dartResult))
/* print output end */