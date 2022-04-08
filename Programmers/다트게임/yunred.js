function solution(dartResult) {
  var answer = 0;
  let num = [];
  let tmp = 0;
  for (let i = 0; i < dartResult.length; i++) {
    if (!isNaN(dartResult[i])) {
      if (
        dartResult[i] !== '0' ||
        (dartResult[i] === '0' && dartResult[i - 1] !== '1')
      ) {
        i > 0 ? num.push(tmp) : num;
      }
      dartResult[i - 1] === '1' && dartResult[i] === '0'
        ? (tmp = 10)
        : (tmp = Number(dartResult[i]));
    } else {
      switch (dartResult[i]) {
        case 'S':
          tmp = Math.pow(tmp, 1);
          break;
        case 'D':
          tmp = Math.pow(tmp, 2);
          break;
        case 'T':
          tmp = Math.pow(tmp, 3);
          break;
        case '#':
          tmp = tmp * -1;
          break;
        case '*':
          num.length > 0
            ? (num[num.length - 1] = num[num.length - 1] * 2)
            : num;
          tmp = tmp * 2;
          break;
      }
    }
    if (i === dartResult.length - 1) {
      num.push(tmp);
    }
  }
  answer = num.reduce((a, b) => a + b);
  return answer;
}

console.log(solution('1S2D*3T'));
