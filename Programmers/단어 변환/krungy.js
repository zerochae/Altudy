/* get input */
const begin = "hit";
const target = "cog";
const words = ["hot", "dot", "dog", "lot", "log", "cog"]; // output = 4

// const begin = "hit";
// const target = "cog";
// const words =  ["hot", "dot", "dog", "lot", "log"]; // output = 0
/* get input end */

/* solve */
const isChanged = (before, after) => {
  let isChecked = false;
  const afterItor = after[Symbol.iterator]();

  for (const string of before) {
    if (string === afterItor.next().value) continue;
    if (isChecked) {
      isChecked = false;
      break;
    }

    isChecked = true;
  }

  return isChecked;
};

function solution(begin, target, words) {
  let answer = 0;
  let queue = [begin];
  let foundWordList = [];

  if (!words.includes(target)) return 0;

  while (queue.length) {
    const curWord = queue.shift();

    if (curWord === target) return answer;

    for (let i = 0; i < words.length; i++) {
      if (isChanged(words[i], curWord)) {
        foundWordList.push(words[i]);
      }
    }
    if (queue.length < 1) {
      answer++;
      while (foundWordList.length) {
        queue.push(foundWordList.shift());
      }
      foundWordList = [];
    }
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(begin, target, words);
console.log(output);
/* print output end */
