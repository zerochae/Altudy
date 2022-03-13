function keypadPosition(num) {
  let keypad = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
  ];
  if (keypad[0].indexOf(num) > -1) {
    return [0, keypad[0].indexOf(num)];
  }
  if (keypad[1].indexOf(num) > -1) {
    return [1, keypad[1].indexOf(num)];
  }
  if (keypad[2].indexOf(num) > -1) {
    return [2, keypad[2].indexOf(num)];
  }
  if (num === 0) return [3, 1];
}

function diffPosition(num1, num2) {
  return Math.abs(num1[0] - num2[0]) + Math.abs(num1[1] - num2[1]);
}

function solution(numbers, hand) {
  var answer = '';
  let rightHand = [3, 2];
  let leftHand = [3, 0];
  let position;
  function useRightHand() {
    rightHand = position;
    answer += 'R';
  }
  function useLeftHand() {
    leftHand = position;
    answer += 'L';
  }
  for (let x of numbers) {
    position = keypadPosition(x);
    console.log(position);
    if (position[1] === 0) {
      useLeftHand();
    } else if (position[1] === 2) {
      useRightHand();
    } else if (position[1] === 1) {
      if (
        diffPosition(position, rightHand) < diffPosition(position, leftHand)
      ) {
        useRightHand();
      } else if (
        diffPosition(position, leftHand) < diffPosition(position, rightHand)
      ) {
        useLeftHand();
      } else {
        if (hand === 'right') {
          useRightHand();
        } else {
          useLeftHand();
        }
      }
    }
  }
  return answer;
}

console.log(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], 'right'));
