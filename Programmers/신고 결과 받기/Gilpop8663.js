/* get input */
let id_list = ["muzi", "frodo", "apeach", "neo"];
let report = [
  "muzi frodo",
  "apeach frodo",
  "frodo neo",
  "muzi neo",
  "apeach muzi",
];
let k = 2;
/* get input end */

/* solve */
function solution(id_list, report, k) {
  var answer = [];

  let countReport = [];
  for (let i = 0; i < id_list.length; i++) {
    countReport.push({ id: id_list[i], count: 0, reportUser: [] });
  }

  for (let i = 0; i < report.length; i++) {
    let users = report[i].split(" ");

    const findIndex = countReport.findIndex((item) => item.id === users[0]);
    const reportFindIndex = countReport.findIndex(
      (item) => item.id === users[1]
    );
    if (countReport[findIndex].reportUser.indexOf(users[1]) < 0) {
      countReport[findIndex].reportUser.push(users[1]);
      countReport[reportFindIndex].count++;
    }
  }

  for (let i = 0; i < id_list.length; i++) {
    let howMuch = 0;
    for (let j = 0; j < countReport[i].reportUser.length; j++) {
      let who = countReport[i].reportUser[j];
      const findIndex = countReport.findIndex((item) => item.id === who);
      if (countReport[findIndex].count >= k) {
        howMuch++;
      }
    }
    answer.push(howMuch);
  }

  return answer;
}
/* solve end */

/* print output */
console.log(solution(id_list, report, k));
/* print output end */
