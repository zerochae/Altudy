/* get input */
let numbers = [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2];
let hand = "left";
/* get input end */

/* solve */
function solution(numbers, hand) {
  var answer = "";
  let left = { x: 1, y: 1 };
  let right = { x: 3, y: 1 };
  let numberArr = [];
  let numberAnswerArr = [];
  let userHand = hand[0].toUpperCase();
  for (let i = 1; i < 4; i++) {
    for (let j = 1; j < 5; j++) {
      numberArr.push({ x: i, y: j });
    }
  }

  for (let i = 0; i < numbers.length; i++) {
    if (numbers[i] === 1) {
      numberAnswerArr.push(numberArr[3]);
    } else if (numbers[i] === 2) {
      numberAnswerArr.push(numberArr[7]);
    } else if (numbers[i] === 3) {
      numberAnswerArr.push(numberArr[11]);
    } else if (numbers[i] === 4) {
      numberAnswerArr.push(numberArr[2]);
    } else if (numbers[i] === 5) {
      numberAnswerArr.push(numberArr[6]);
    } else if (numbers[i] === 6) {
      numberAnswerArr.push(numberArr[10]);
    } else if (numbers[i] === 7) {
      numberAnswerArr.push(numberArr[1]);
    } else if (numbers[i] === 8) {
      numberAnswerArr.push(numberArr[5]);
    } else if (numbers[i] === 9) {
      numberAnswerArr.push(numberArr[9]);
    } else if (numbers[i] === 0) {
      numberAnswerArr.push(numberArr[4]);
    }
  }

  for (let i = 0; i < numberAnswerArr.length; i++) {
    if (numberAnswerArr[i].x === 1) {
      answer += "L";
      left = { x: 1, y: numberAnswerArr[i].y };
    } else if (numberAnswerArr[i].x === 3) {
      answer += "R";
      right = { x: 3, y: numberAnswerArr[i].y };
    } else {
      let leftSum =
        Math.abs(numberAnswerArr[i].x - left.x) +
        Math.abs(numberAnswerArr[i].y - left.y);
      let rightSum =
        Math.abs(numberAnswerArr[i].x - right.x) +
        Math.abs(numberAnswerArr[i].y - right.y);
      if (leftSum < rightSum) {
        answer += "L";
        left = { x: 2, y: numberAnswerArr[i].y };
      } else if (leftSum > rightSum) {
        answer += "R";
        right = { x: 2, y: numberAnswerArr[i].y };
      } else if (leftSum === rightSum) {
        answer += userHand;
        if (userHand === "L") {
          left = { x: 2, y: numberAnswerArr[i].y };
        } else if (userHand === "R") {
          right = { x: 2, y: numberAnswerArr[i].y };
        }
      }
    }
  }

  return answer;
}
/* solve end */

/* print output */
console.log(solution(numbers, hand));
/* print output end */
