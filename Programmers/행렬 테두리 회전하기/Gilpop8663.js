/* get input */
const rows = 6;
const columns = 6;
const queries = [
  [2, 2, 5, 4],
  [3, 3, 6, 6],
  [5, 1, 6, 3],
];

/* get input end */

/* solve */
function solution(rows, columns, queries) {
  var answer = [];
  let arr = [];
  for (let i = 1; i <= rows; i++) {
    for (let j = 1; j <= columns; j++) {
      arr.push({
        x: j,
        y: i,
        value: (i - 1) * columns + j,
      });
    }
  }
  arr.sort((a, b) => b.value - a.value);
  for (let i = 0; i < queries.length; i++) {
    let min = Number.MAX_SAFE_INTEGER;
    const a = arr.map((item) => {
      if (
        item.x >= queries[i][1] &&
        item.x <= queries[i][3] &&
        item.y >= queries[i][0] &&
        item.y <= queries[i][2]
      ) {
        if (item.y === queries[i][0]) {
          if (min > item.value) {
            min = item.value;
          }
          if (item.x === queries[i][3]) {
            return { ...item, y: item.y + 1 };
          } else {
            return { ...item, x: item.x + 1 };
          }
        } else if (item.y === queries[i][2]) {
          if (min > item.value) {
            min = item.value;
          }
          if (item.x === queries[i][1]) {
            return { ...item, y: item.y - 1 };
          } else {
            return { ...item, x: item.x - 1 };
          }
        } else if (item.x === queries[i][1]) {
          if (min > item.value) {
            min = item.value;
          }
          if (item.y === queries[i][0]) {
            return { ...item, x: item.x + 1 };
          } else {
            return { ...item, y: item.y - 1 };
          }
        } else if (item.x === queries[i][3]) {
          if (min > item.value) {
            min = item.value;
          }
          if (item.y === queries[i][2]) {
            return { ...item, x: item.x - 1 };
          } else {
            return { ...item, y: item.y + 1 };
          }
        } else {
          return item;
        }
      } else {
        return item;
      }
    });
    answer.push(min);
    arr = a;
  }
  return answer;
}
/* solve end */

/* print output */
console.log(solution(rows, columns, queries));
/* print output end */
