/* get input */
let expression = "100-200*300-500+20";

/* get input end */

/* solve */
function solution(expression) {
  var answer = Number.MIN_SAFE_INTEGER;
  let arr = [];
  let operation = [];
  let tmp = Array.from({ legnth: 4 }, () => 0);
  let ch = Array.from({ length: 4 }, () => 0);
  let mathArr = ["-", "+", "*", "/"];
  let numbers = expression.split(/[\*\/\-\+]/gi);
  expression.split("").forEach((item) => {
    if (isNaN(item)) {
      operation.push(item);
    }
  });
  let totalArr = [];
  numbers.forEach((item, i) => {
    totalArr.push(+item);
    totalArr.push(operation[i]);
  });
  totalArr.pop();
  //   console.log(totalArr);

  function DFS(L) {
    if (L === 4) {
      //   arr.push(tmp.slice());
      //   console.log(tmp);
      //   console.log(operation);
      let result = 0;
      let newTotalArr = totalArr.slice();
      for (let k = 0; k < operation.length; k++) {
        let numIndex = newTotalArr.indexOf(tmp[0]);
        if (numIndex !== -1) {
          result = eval(
            newTotalArr[numIndex - 1] + tmp[0] + newTotalArr[numIndex + 1]
          );

          let what = [
            ...newTotalArr.slice(0, numIndex - 1),
            result,
            ...newTotalArr.slice(numIndex + 2),
          ];
          newTotalArr = what;
          if (newTotalArr.length === 1) continue;
          //   console.log(newTotalArr + "Zxcxxx");
        }
      }
      for (let k = 0; k < operation.length; k++) {
        let numIndex = newTotalArr.indexOf(tmp[1]);
        if (numIndex !== -1) {
          result = eval(
            newTotalArr[numIndex - 1] + tmp[1] + newTotalArr[numIndex + 1]
          );

          let what = [
            ...newTotalArr.slice(0, numIndex - 1),
            result,
            ...newTotalArr.slice(numIndex + 2),
          ];
          newTotalArr = what;
          //   console.log(newTotalArr + "Zxc");
          if (newTotalArr.length === 1) continue;
        }
      }
      for (let k = 0; k < operation.length; k++) {
        let numIndex = newTotalArr.indexOf(tmp[2]);
        if (numIndex !== -1) {
          result = eval(
            newTotalArr[numIndex - 1] + tmp[2] + newTotalArr[numIndex + 1]
          );

          let what = [
            ...newTotalArr.slice(0, numIndex - 1),
            result,
            ...newTotalArr.slice(numIndex + 2),
          ];
          newTotalArr = what;
          //   console.log(newTotalArr + "asd", newTotalArr.length);
          if (newTotalArr.length === 1) continue;
        }
      }
      for (let k = 0; k < operation.length; k++) {
        let numIndex = newTotalArr.indexOf(tmp[3]);
        if (numIndex !== -1) {
          result = eval(
            newTotalArr[numIndex - 1] + tmp[3] + newTotalArr[numIndex + 1]
          );

          let what = [
            ...newTotalArr.slice(0, numIndex - 1),
            result,
            ...newTotalArr.slice(numIndex + 2),
          ];
          newTotalArr = what;
          //   console.log(newTotalArr + "qwe2");
          if (newTotalArr.length === 1) continue;
        }
      }

      //   console.log(newTotalArr);
      answer = Math.max(answer, Math.abs(newTotalArr[0]));
    } else {
      for (let i = 0; i < 4; i++) {
        if (ch[i] === 0) {
          ch[i] = 1;
          tmp[L] = mathArr[i];
          DFS(L + 1);
          ch[i] = 0;
        }
      }
    }
  }
  DFS(0);
  //   console.log(eval(expression));
  return answer;
}
/* solve end */

/* print output */
console.log(solution(expression));
/* print output end */
