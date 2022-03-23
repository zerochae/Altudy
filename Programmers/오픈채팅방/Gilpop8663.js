/* get input */
const record = [
  "Enter uid1234 Muzi",
  "Enter uid4567 Prodo",
  "Leave uid1234",
  "Enter uid1234 Prodo",
  "Change uid4567 Ryan",
];
/* get input end */

/* solve */

/*solution 1 (시간초과)
function solution(record) {
  var answer = [];
  let userArr = [];
  record.forEach((cur) => {
    const [state, id, name] = cur.split(" ");
    const findIndex = userArr.findIndex((ele) => {
      return ele.id === id;
    });
    if (state === "Enter") {
      if (findIndex !== -1) {
        const newArr = [
          ...userArr.slice(0, findIndex),
          { id: id, name: name },
          ...userArr.slice(findIndex + 1),
        ];
        userArr = newArr;
      } else {
        userArr.push({ id: id, name: name });
      }
    } else if (state === "Change") {
      if (findIndex !== -1) {
        const newArr = [
          ...userArr.slice(0, findIndex),
          { id: id, name: name },
          ...userArr.slice(findIndex + 1),
        ];
        userArr = newArr;
      }
    }
  });
  record.forEach((cur) => {
    const [state, id, _] = cur.split(" ");
    const findIndex = userArr.findIndex((ele) => ele.id === id);
    if (findIndex === -1) {
      return;
    }
    if (state === "Enter") {
      answer.push(enterUser(userArr[findIndex].name));
    } else if (state === "Leave") {
      answer.push(leaveUser(userArr[findIndex].name));
    }
  });
  return answer;
}

function enterUser(name) {
  return `${name}님이 들어왔습니다.`;
}

function leaveUser(name) {
  return `${name}님이 나갔습니다.`;
}
*/

function solution(record) {
  var answer = [];
  let users = {};
  record.forEach((cur) => {
    const [state, id, name] = cur.split(" ");
    if (state !== "Leave") users[id] = name;
  });

  record.forEach((cur) => {
    const [state, id, name] = cur.split(" ");
    if (state === "Enter") {
      answer.push(enterUser(users[id]));
    } else if (state === "Leave") {
      answer.push(leaveUser(users[id]));
    }
  });
  return answer;
}

function enterUser(name) {
  return `${name}님이 들어왔습니다.`;
}

function leaveUser(name) {
  return `${name}님이 나갔습니다.`;
}

/* solve end */

/* print output */
console.log(solution(record));
/* print output end */
