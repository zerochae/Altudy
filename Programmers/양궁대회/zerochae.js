const n = 5;
const info = [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0];

let max = -1;
let result = [-1];

const solution = (n, score_apeach) => {

  const score_lion = new Array(11).fill(0);
  dfs(0, score_apeach, score_lion, n);

  return result;
};

const dfs = (depth, score_apeach, score_lion, n) => {

  if (depth === n) {
    getScore(score_apeach, score_lion);
    return;
  }
  for (let i = 0; i <= 10 && score_lion[i] <= score_apeach[i]; i++) {
    score_lion[i]++;
    dfs(depth + 1, score_apeach, score_lion, n);
    score_lion[i]--;
  }

};

const getScore = (score_apeach, score_lion) => {

  let apeach = 0;
  let lion = 0;

  for (let i = 0; i <= 10; i++)
    if (score_apeach[i] !== 0 || score_lion[i] !== 0)
      score_lion[i] > score_apeach[i] ? (lion += 10 - i) : (apeach += 10 - i);

  if (lion > apeach && lion - apeach >= max) {
    result = [...score_lion];
    max = lion - apeach;
  }
};

console.log(solution(n, info));
