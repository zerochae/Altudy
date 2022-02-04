const n = 10;
const info = [0,0,0,0,0,0,0,0,3,4,3];

let max = Number.MIN_VALUE;
let result = [-1];

const solution = (n, score_apeach) => {
  const score_lion = new Array(11).fill(0);

  dfs(0, score_apeach, score_lion, n);

  return result;
};

const dfs = (depth, score_apeach, score_lion, shot) => {

  if(shot < 0) return;

  if (depth === 10) {

    let apeach = 0; let lion = 0; score_lion[10] = shot;
    
    for (let i in score_lion)
    if (score_apeach[i] !== 0 || score_lion[i] !== 0)
    score_lion[i] > score_apeach[i] ? (lion += 10 - i) : (apeach += 10 - i);
    
    if (lion - apeach > max) {
      result = [...score_lion];
      max = lion - apeach;
    } else if (lion - apeach === max) result = [...compare(result,score_lion)]
    
    return;
  }
    score_lion[depth] = score_apeach[depth] + 1; 
    dfs(depth + 1, score_apeach, score_lion, shot - score_lion[depth]);
    score_lion[depth] = 0; 
    dfs(depth + 1, score_apeach, score_lion, shot);
};

const compare = (arr1 , arr2) => {

  arr1 = arr1.reverse();
  arr2 = arr2.reverse();

  for(let index in arr1){
    if(arr1[index] > arr2[index]) return arr1.reverse();
    else if(arr1[index] < arr2[index]) return arr2.reverse();
  }
}