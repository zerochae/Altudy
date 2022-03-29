function convertBinary(arr, n) {
  let num = arr;
  let tmpBinary = [];
  while (true) {
    tmpBinary.unshift(num % 2);
    num = parseInt(num / 2);
    if (num === 0) break;
  }
  while (tmpBinary.length < n) {
    tmpBinary.unshift(0);
  }
  return tmpBinary;
}

function solution(n, arr1, arr2) {
  var answer = [];
  let binaryArr1 = [];
  let binaryArr2 = [];
  for (let i = 0; i < arr1.length; i++) {
    binaryArr1.push(convertBinary(arr1[i], n));
    binaryArr2.push(convertBinary(arr2[i], n));
  }
  for (let i = 0; i < binaryArr1.length; i++) {
    let tmpcode = '';
    for (let j = 0; j < binaryArr1[i].length; j++) {
      if (binaryArr1[i][j] === 1 || binaryArr2[i][j] === 1) {
        tmpcode += '#';
      } else tmpcode += ' ';
    }
    answer.push(tmpcode);
    tmpcode = '';
  }
  return answer;
}

console.log(solution(5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28]));
