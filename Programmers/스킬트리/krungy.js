/* get input */
const skill = "CBD";
const skill_trees = ["BACDE", "CBADF", "AECB", "BDA"]; // output = 2
/* get input end */

/* solve */
function solution(skill, skill_trees) {
  var answer = 0;

  for (let i = 0; i < skill_trees.length; i++) {
    let skillQueue = skill.split("");
    let isError = false;

    for (let j = 0; j < skill_trees[i].length; j++) {
      let currentSkill = skill_trees[i][j];
      if (skillQueue.indexOf(currentSkill) !== -1) {
        skillQueue[0] === currentSkill ? skillQueue.shift() : (isError = true);
      }
    }
    isError ? (isError = false) : answer++;
  }
  return answer;
}
/* solve end */

/* print output */
const output = solution(skill, skill_trees);
console.log(output);
/* print output end */
