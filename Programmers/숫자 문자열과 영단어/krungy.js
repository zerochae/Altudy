/* get input */
const s = "one4seveneight"; // output = 1478
// const s = "23four5six7"; // output = 234567
// const s = "2three45sixseven"; // output = 234567
// const s = "123"; // output = 123
/* get input end */

/* solve */
function solution(s) {
  var answer = "";
  const words = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
  ];
  let word = "";

  for (let i = 0; i < s.length; i++) {
    if (!(s[i] >= "a" && s[i] <= "z")) {
      answer += s[i];
      continue;
    }

    word += s[i];
    if (words.indexOf(word) !== -1) {
      answer += words.indexOf(word);
      word = "";
    }
  }
  return answer * 1;
}
/* solve end */

/* print output */
const output = solution(s);
console.log(output);
/* print output end */
