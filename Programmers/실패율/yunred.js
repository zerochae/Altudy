function solution(N, stages) {
  var answer = [];
  let arr = [];
  let n = 1;
  while (n < N + 1) {
    let tmp = new Object();
    tmp.stage = n;
    tmp.fail = 0;
    tmp.people = stages.length;
    arr.push(tmp);
    n++;
  }
  stages.forEach(el => {
    if (el <= N) {
      arr[el - 1].fail++;
      for (let i = el; i < N; i++) {
        arr[i].people--;
      }
    }
  });
  arr.forEach(el => {
    el.rate = el.fail / el.people;
  });
  arr.sort((a, b) => b.rate - a.rate);
  arr.forEach(el => {
    answer.push(el.stage);
  });
  return answer;
}
console.log(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]));
