function solution(n, lost, reserve) {
  var answer = 0;
  let lostnumber;
  let deleteLostArr = [];
  lost.sort((a, b) => a - b);
  reserve.sort((a, b) => a - b);

  //도난 여분 중복된 경우 빼기
  lost.map((item, idx) => {
    for (let i = 0; i < lost.length; i++) {
      if (item === reserve[i]) {
        reserve.splice(i, 1);
        deleteLostArr.push(idx);
      }
    }
  });
  if (deleteLostArr.length > 0) {
    for (let i = deleteLostArr.length - 1; i > -1; i--) {
      lost.splice(deleteLostArr[i], 1);
    }
  }

  lostnumber = lost.length;
  lost.map(item => {
    for (let i = 0; i < reserve.length; i++) {
      if (item === reserve[i] - 1 || item === reserve[i] + 1) {
        reserve.splice(i, 1);
        lostnumber--;
        break;
      }
    }
  });
  answer = n - lostnumber;
  return answer;
}

console.log(
  solution(
    30,
    [1, 2, 7, 9, 10, 11, 12, 14, 15, 16, 18, 20, 21, 24, 25, 27],
    [
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 20, 22, 23, 24,
      25, 26, 27, 28,
    ]
  )
);
