/* get input */
let infos = [
  "java backend junior pizza 150",
  "python frontend senior chicken 210",
  "python frontend senior chicken 150",
  "cpp backend senior pizza 260",
  "java backend junior chicken 80",
  "python backend senior chicken 50",
];
let query = [
  "java and backend and junior and pizza 100",
  "python and frontend and senior and chicken 200",
  "cpp and - and senior and pizza 250",
  "- and backend and senior and - 150",
  "- and - and - and chicken 100",
  "- and - and - and - 150",
];
/* get input end */

/* solve */
function solution(info, query) {
  var answer = [];
  let map = {};

  function combination(infos, score, map, start) {
    let key = infos.join("");
    let value = map[key];

    if (value) {
      map[key].push(+score);
    } else {
      map[key] = [+score];
    }
    for (let i = start; i < infos.length; i++) {
      let combiArr = [...infos];
      combiArr[i] = "-";
      combination(combiArr, score, map, i + 1);
    }
  }

  function binarySearch(map, key, score) {
    let scoreArr = map[key];

    if (scoreArr) {
      let start = 0;
      let end = scoreArr.length;
      while (start < end) {
        let mid = Math.floor((start + end) / 2);

        if (scoreArr[mid] >= score) {
          end = mid;
        } else if (scoreArr[mid] < score) {
          start = mid + 1;
        }
      }
      return scoreArr.length - start;
    } else {
      return 0;
    }
  }

  for (let i = 0; i < info.length; i++) {
    let infos = info[i].split(" ");
    let score = infos.pop();
    combination(infos, score, map, 0);
  }

  for (let key in map) {
    map[key].sort((a, b) => a - b);
  }

  for (let i = 0; i < query.length; i++) {
    let querys = query[i].replace(/ and/g, "").split(" ");
    let score = Number(querys.pop());
    // console.log(querys, score);
    answer.push(binarySearch(map, querys.join(""), score));
  }

  return answer;
}

// function solution(info, query) {
//   var answer = [];
//   let map = {};

//   function combination(infos, score, map, start) {
//     let key = infos.join(""); //키 값으로 쓸거 합쳐주기
//     let value = map[key]; //값 있는지 없는지 확인해주기

//     if (value) {
//       //값이 있으면 push
//       map[key].push(score);
//     } else {
//       //값이 없으면 프로퍼티 만들어줘야 됨
//       map[key] = [score];
//     }
//     //여기서는 - 를 이용해 조합 만들어주기
//     for (let i = start; i < infos.length; i++) {
//       let combiArr = [...infos]; //전개 연산자
//       combiArr[i] = "-";
//       combination(combiArr, score, map, i + 1);
//     }
//   }

//   // function binarySearch(map, key, score) {
//   //   let scoreArr = map[key];

//   //   if (scoreArr) {
//   //     let start = 0;
//   //     let end = scoreArr.length;
//   //     while (start < end) {
//   //       let mid = Math.floor((start + end) / 2);

//   //       if (scoreArr[mid] >= score) {
//   //         //현재 가르키는 값보다 내가 찾는 값이
//   //         end = mid;
//   //       } else if (scoreArr[mid] < score) {
//   //         start = mid + 1;
//   //       }
//   //     }
//   //     return scoreArr.length - start;
//   //   } else return 0;
//   // }

//   for (let i = 0; i < info.length; i++) {
//     let infos = info[i].split(" ");
//     let score = infos.pop();
//     combination(infos, score, map, 0);
//   }
//   console.log(map);

//   // for (let key in map) {
//   //   map[key].sort((o1, o2) => o1 - o2);
//   // }

//   // for (let i = 0; i < query.length; i++) {
//   //   let querys = query[i].replace(/ and /g, "").split(" ");
//   //   let score = Number(querys.pop());
//   //   answer.push(binarySearch(map, querys.join(""), score));
//   // }

//   return answer;
// }

// function solution(infos, query) {
//   var answer = [];

//   let infoObj = {};

//   for (let lang of ["cpp", "java", "python", "-"]) {
//     for (let job of ["backend", "frontend", "-"]) {
//       for (let career of ["junior", "senior", "-"]) {
//         for (let food of ["pizza", "chicken", "-"]) {
//           infoObj[lang + job + career + food] = [];
//         }
//       }
//     }
//   }

//   for (let info of infos) {
//     info = info.split(" ");
//     for (let lang of [info[0], "-"]) {
//       for (let job of [info[1], "-"]) {
//         for (let career of [info[2], "-"]) {
//           for (let food of [info[3], "-"]) {
//             // console.log(lang, job, career, food);
//             infoObj[lang + job + career + food].push(+info[4]);
//           }
//         }
//       }
//     }
//   }

//   for (let key of Object.keys(infoObj)) {
//     infoObj[key].sort((a, b) => b - a);
//   }
//   // infoObj = infoObj[].sort((a, b) => b - a);

//   //   console.log(infoObj);
//   for (let q of query) {
//     q = q.replace(/ and/gi, "");
//     q = q.split(" ");
//     let score = q[4];
//     q.pop();
//     // console.log(score);
//     // console.log(q.join(""));
//     let newArr = Object.values(infoObj[q.join("")]);
//     // console.log(newArr);
//     let right = newArr.length - 1;
//     // console.log(newArr);
//     let left = 0;
//     let cnt = 0;
//     let tmp = newArr.length;
//     // console.log(high, low, mid);
//     // let mid = Math.ceil((right + left) / 2);
//     // console.log(newArr[mid], mid);
//     // while (newArr[mid] <= score) {
//     //   mid = Math.ceil((right + left) / 2);
//     //   if (newArr[mid] <= score) right = mid - 1;
//     //   else left = mid + 1;
//     // }
//     // console.log(mid, left, right);
//     // let num = newArr.filter((item) => item >= score);
//     let what = binarySearch(newArr, score);
//     console.log(what);

//     answer.push(newArr.length - left);
//   }
//   return answer;
// }

// const binarySearch = (arr, target) => {
//   let left = 0;
//   let right = arr.length - 1;
//   let mid = Math.floor((left + right) / 2);
//   while (left <= right) {
//     if (arr[mid] === target) return mid;
//     if (arr[mid] < target) left = mid + 1;
//     else right = mid - 1;

//     mid = Math.floor((left + right) / 2);
//   }
//   // 기준이 되는 인덱스는, 여기서 나온 값보다 항상 1이 더 큽니다. 따라서 +1을 해주죠!
//   return mid + 1;
// };

// function twoFn (start,end,){
//   while low <= high:
//   mid = (low + high) // 2

//   if query_score <= info_score[mid]:
//       tmp = mid
//       high = mid - 1

//   else:
//       low = mid + 1
// }
//   console.log(infoObj);

// function solution(info, query) {
//   var answer = [];

//   let n = info.length;
//   let m = query.length;
//   info.forEach((item, i) => (info[i] = item.split(" ")));
//   for (let lang of info) {
//     console.log(lang);
//   }
//   info = info.sort((a, b) => b[4] - a[4]);
//   console.log(info);
//   for (let i = 0; i < m; i++) {
//     query[i] = query[i].split(" ").filter((item) => item !== "and");
//     let cnt = 0;
//     for (let j = 0; j < n; j++) {
//       if (+info[j][4] >= +query[i][4]) {
//         if (
//           (query[i][0] === "-" || info[j][0] === query[i][0]) &&
//           (query[i][1] === "-" || info[j][1] === query[i][1]) &&
//           (query[i][2] === "-" || info[j][2] === query[i][2]) &&
//           (query[i][3] === "-" || info[j][3] === query[i][3]) &&
//           +info[j][4] >= +query[i][4]
//         ) {
//           cnt++;
//         }
//       } else continue;
//     }
//     // console.log(cnt);
//     answer.push(cnt);
//   }
//   return answer;
// }
/* solve end */

/* print output */
console.log(solution(infos, query));
/* print output end */
