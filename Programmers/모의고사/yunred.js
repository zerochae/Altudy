const grade = (score, answer, my_answer, order) => {
  if (answer === my_answer) score[order - 1]++;
};

function solution(answers) {
  var answer = [];
  const first = [1, 2, 3, 4, 5];
  const second = [2, 1, 2, 3, 2, 4, 2, 5];
  const third = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
  let score = Array.from({ length: 3 }, () => 0);
  for (let i = 0; i < answers.length; i++) {
    grade(score, answers[i], first[i % first.length], 1);
    grade(score, answers[i], second[i % second.length], 2);
    grade(score, answers[i], third[i % third.length], 3);
  }
  let max_score = Math.max(...score);
  for (let i = 0; i < score.length; i++) {
    if (score[i] === max_score) answer.push(i + 1);
  }
  return answer;
}

console.log(solution([1, 2, 3, 4, 5]));
