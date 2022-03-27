/* get input */
const n=6;
const arr1=	[46, 33, 33 ,22, 31, 50];
const arr2 =[27 ,56, 19, 14, 14, 10];

/* get input end */

/* solve */
function solution(n, arr1, arr2) {
    var answer = [];
    for(let i=0;i<n;i++){
        let first = arr1[i].toString(2)
        let second = arr2[i].toString(2)
        let sum = +first + +second
        sum = sum.toString()
            while(sum.length <n){
                sum = "0" + sum
            }
            sum=sum.split("")
            for(let j=0;j<sum.length;j++){
                if(+sum[j] !== 0) sum[j] = "#"
                else sum[j] = " "
            }
            answer.push(sum.join(""))
            
        }
        return answer;
    }
    /* solve end */
    
    /* print output */
    console.log(solution(n,arr1,arr2))
    /* print output end */