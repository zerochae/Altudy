/* get input */
const record = [
  "Enter uid1234 Muzi",
  "Enter uid4567 Prodo",
  "Leave uid1234",
  "Enter uid1234 Prodo",
  "Change uid4567 Ryan",
]; // output = ["Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."]
/* get input end */

/* solve */
function solution(record) {
  var answer = [];
  let user = {};
  const MESSAGE = {
    Enter: "님이 들어왔습니다.",
    Leave: "님이 나갔습니다.",
  };

  for (const message of record) {
    const [stat, uid, nickName] = message.split(" ");

    if (nickName) {
      user[uid] = nickName;
    }
  }

  for (const message of record) {
    const [cmd, uid, nickName] = message.split(" ");

    if (cmd === "Change") continue;

    answer.push(`${user[uid]}${MESSAGE[cmd]}`);
  }

  return answer;
}
/* solve end */

/* print output */
const output = solution(a, b);
console.log(output);
/* print output end */
