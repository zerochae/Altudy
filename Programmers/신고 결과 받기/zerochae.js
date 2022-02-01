let id_list = ["muzi", "frodo", "apeach", "neo"];
let report = [
  "muzi frodo",
  "apeach frodo",
  "frodo neo",
  "muzi neo",
  "apeach muzi",
];
let k = 2;

solution(id_list, report, k);

function solution(id_list, report, k) {

  class member {
    constructor(nm, mail, count, report) {
      this.nm = nm;
      this.report = report;
      this.mail = mail;
      this.count = count;
    }
  }

  let answer = [];
  let memberList = []; // 멤버들 정보

  for (let mem of id_list) {
    memberList.push(new member(mem, 0, 0, [])); // 멤버 기본 정보 저장
  }

  let set = new Set();

  for (let rep of report) {
    set.add(rep);
  }

  for (let item of set) {
    let reporter = item.split(" ")[0];
    let reported = item.split(" ")[1];

    memberList.map((mem) => {
      if (mem.nm === reporter) return mem.report.push(reported);
    });
  }

  for (mem of memberList) {
    for (rep of mem.report) {
      memberList.map((member) => {
        if (member.nm === rep) {
          member.count++;
        }
      });
    }
  }

  for (let mem of memberList) {
    if (mem.count >= k) {
      memberList.map((member) => {
        if (member.report.includes(mem.nm)) member.mail++;
      });
    }
  }

  for (let mem of memberList) {
    answer.push(mem.mail);
  }

  console.log(answer);

  return answer;
}