/* get input */
const orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"];
const course = [2, 3, 4]; // output = ["AC", "ACDE", "BCFG", "CDE"]
// const orders = ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"];
// const course = [2, 3, 5]; // output = ["ACD", "AD", "ADE", "CD", "XYZ"]
// const orders = ["XYZ", "XWY", "WXA"];
// const course = [2, 3, 4]; // output = ["WX", "XY"]
/* get input end */

/* solve */
function combination(order, courseCnt) {
  let result = [];

  if (courseCnt === 1) {
    return order.map((item) => [item]);
  }
  order.map((picked, index, originArray) => {
    let exceptPicked = originArray.slice(index + 1);
    let recurCombination = combination(exceptPicked, courseCnt - 1);
    let joinedResult = recurCombination.map((item) => [picked, ...item]);
    result.push(...joinedResult);
  });
  return result;
}

function solution(orders, course) {
  var answer = [];
  let sortedOrders = [];
  let combMenuList = [];
  let combinedMap = {};

  sortedOrders = orders.map((item) => item.split("").sort());

  for (let i = 0; i < sortedOrders.length; i++) {
    for (let j = 0; j < course.length; j++) {
      combMenuList.push(...combination(sortedOrders[i], course[j]));
    }
  }
  combMenuList.map((item) => {
    item = item.join("");

    combinedMap[item] =
      combinedMap[item] === undefined ? 1 : combinedMap[item] + 1;
  });
  let combinedArray = Object.entries(combinedMap);

  for (let i = 0; i < course.length; i++) {
    let max = 2;
    let findMax = [];
    combinedArray.map((item) => {
      if (item[0].length === course[i] && item[1] >= 2) {
        if (item[1] >= max) max = item[1];
        findMax.push(item);
      }
    });
    findMax.map((item) => {
      if (item[1] === max) {
        answer.push(item[0]);
      }
    });
  }

  return answer.sort();
}
/* solve end */

/* print output */
const output = solution(orders, course);
console.log(output);
/* print output end */
