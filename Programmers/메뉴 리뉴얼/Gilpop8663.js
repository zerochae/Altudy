/* get input */
const orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"];
const course = [2, 3, 4];
/* get input end */

const getCombinations = function (arr, selectNumber) {
  let results = [];
  if (selectNumber === 1) return arr.map((el) => el);
  // console.log(results);
  // n개중에서 1개 선택할 때(nC1), 바로 모든 배열의 원소 return

  arr.forEach((fixed, index, origin) => {
    // console.log(fixed, index, origin);
    const rest = origin.slice(index + 1);
    // console.log(rest);
    // 해당하는 fixed를 제외한 나머지 뒤
    const combinations = getCombinations(rest, selectNumber - 1);
    // console.log("콤비네이션", combinations);
    // 나머지에 대해서 조합을 구한다.
    const attached = combinations.map((el) => fixed + el);
    //  돌아온 조합에 떼 놓은(fixed) 값 붙이기
    results.push(...attached);
    // return console.log(attached);
    // 배열 spread syntax 로 모두다 push
  });
  // console.log(results);

  return results; // 결과 담긴 results return
};

function solution(orders, course) {
  var answer = [];
  let arr = [];
  let result = [];
  for (let i = 0; i < orders.length; i++) {
    let orderArr = orders[i].split("");
    orderArr.sort();
    for (let m = 0; m < course.length; m++) {
      const selectNum = course[m];
      arr = getCombinations(orderArr, selectNum);
      // console.log(arr);
      result = [...arr, ...result];
      if (selectNum === 1) {
        // const textItem = orderArr[k];
        // arr = arrCountFn(arr, textItem);
      } else {
        // const textItem = orderArr[k] + orderArr[k + selectNum];
        // arr = arrCountFn(arr, textItem);
      }
    }
  }

  // console.log(result);

  let countArr = [];

  for (let i = 0; i < result.length; i++) {
    const textItem = result[i];
    countArr = arrCountFn(countArr, textItem);
  }
  countArr.sort();
  for (let i = 0; i < course.length; i++) {
    const selectNum = course[i];
    // console.log(selectNum);
    const newArr = countArr.filter(
      (item) => item.text.length === selectNum && item.count > 1
    );
    newArr.sort((a, b) => b.count - a.count);
    if (newArr[0]) {
      let manyNumber = newArr[0].count;
      let higherText = newArr.filter((item) => item.count === manyNumber);
      // console.log(higherText);
      higherText.map((item) => answer.push(item.text));
    }
  }
  // console.log(countArr);
  answer.sort();
  // orderCountArr.sort((a, b) => b.count - a.count);
  return answer;
}

function arrCountFn(countArray, textItem) {
  const findIndex = countArray.findIndex((item) => item.text === textItem);
  if (findIndex !== -1) {
    let newOrderCountArr = [
      ...countArray.slice(0, findIndex),
      { text: textItem, count: countArray[findIndex].count + 1 },
      ...countArray.slice(findIndex + 1),
    ];
    return newOrderCountArr;
  } else {
    return [...countArray, { text: textItem, count: 1 }];
  }
}
/* solve end */

/* print output */
console.log(solution(orders, course));
/* print output end */
