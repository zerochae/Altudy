function solution(id_list, report, k) {
  var answer = [];
  let reportedArr = Array.from({ length: id_list.length }, () => 0);
  let reportArr = Array.from({ length: id_list.length }, () => []);
  let answerArr = [...reportedArr];
  let uniqueReport = [...new Set(report)];
  for (let x of uniqueReport) {
    let tmp = x.split(' ');
    reportedArr[id_list.indexOf(tmp[1])] += 1;
    reportArr[id_list.indexOf(tmp[0])].push(id_list.indexOf(tmp[1]));
  }
  for (let i = 0; i < reportedArr.length; i++) {
    if (reportedArr[i] >= k) {
      reportArr.forEach((item, index) => {
        if (item.indexOf(i) !== -1) answerArr[index] += 1;
      });
    }
  }
  return (answer = answerArr);
}

console.log(
  solution(
    ['muzi', 'frodo', 'apeach', 'neo'],
    ['muzi frodo', 'apeach frodo', 'frodo neo', 'muzi neo', 'apeach muzi'],
    2
  )
);
