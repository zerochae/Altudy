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
const solution = (record) => {
  
  const map = new Map();

  record.forEach((row) => {
    const [method, id, nick] = row.split(" ");
    method !== "Leave" && map.set(id, nick);
  });

  return record.reduce((result, row) => {
    const [method, id] = row.split(" ");
    const log = `${map.get(id)}님이 ${method === "Enter" ? "들어왔습니다." : "나갔습니다."}`;
    
    return method !== "Change" ? [...result,log] : result;
  }, []);
};
/* solve end */

/* print output */
const output = solution(record);
console.log(output);
/* print output end */
