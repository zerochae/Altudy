/* get input */
let str1 = "abc";
let str2 = "abbb";
/* get input end */

/* solve */
function solution(str1, str2) {
  var answer = 0;
  let arr = [];
  let arr2 = [];
  let both = 0;
  str1 = str1.toLowerCase();
  str2 = str2.toLowerCase();
  for (let i = 0; i < str1.length - 1; i++) {
    if (
      str1[i].charCodeAt() >= 97 &&
      str1[i].charCodeAt() <= 122 &&
      str1[i + 1].charCodeAt() >= 97 &&
      str1[i + 1].charCodeAt() <= 122
    ) {
      arr.push(str1.slice(i, i + 2));
    }
  }
  for (let i = 0; i < str2.length - 1; i++) {
    if (
      str2[i].charCodeAt() >= 97 &&
      str2[i].charCodeAt() <= 122 &&
      str2[i + 1].charCodeAt() >= 97 &&
      str2[i + 1].charCodeAt() <= 122
    ) {
      arr2.push(str2.slice(i, i + 2));
    }
  }
  for (let i = 0; i < arr.length; i++) {
    if (arr2.indexOf(arr[i]) !== -1) {
      arr2[arr2.indexOf(arr[i])] = [];
      both++;
    }
  }
  if (arr.length === 0 && arr2.length === 0) {
    answer = 65536;
  } else {
    answer = Math.floor((both / (arr.length + arr2.length - both)) * 65536);
  }

  return answer;
}
/* solve end */

/* print output */
console.log(solution(str1, str2));
/* print output end */
