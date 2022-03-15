/* get input */
const N = 5;
const stages = [2, 1, 2, 6, 2, 4, 3, 3];
/* get input end*/

/* solve */
function solution(N, stages) {
  var answer = [];
  let itemCount = [];
  let rateArr = [];
  stages.map((item) => {
    const findIndex = itemCount.findIndex((itemCountItem) => {
      return +itemCountItem.title === +item;
    });
    if (findIndex === -1) {
      itemCount.push({ title: item, count: 1 });
    } else {
      itemCount = [
        ...itemCount.slice(0, findIndex),
        { title: item, count: itemCount[findIndex].count + 1 },
        ...itemCount.slice(findIndex + 1),
      ];
    }
  });
  const sortData = itemCount.sort((a, b) => a.title - b.title);
  let user = stages.length;
  sortData.map((item, i) => {
    rateArr.push({ title: item.title, rate: item.count / user });
    user = user - item.count;
  });

  rateArr.sort((a, b) => {
    return b.rate - a.rate;
  });
  console.log(rateArr);
  rateArr.map((item) => {
    if (item.title !== N + 1) answer.push(item.title);
  });
  const lastArr = Array.from({ length: N }, (_, i) => i + 1);
  lastArr.map((item) => {
    if (answer.indexOf(item) === -1) {
      answer.push(item);
    }
  });
  return answer;
}
/* solve end*/

/* print output */
console.log(solution(N, stages));
/* print output end*/
