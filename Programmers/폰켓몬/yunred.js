function solution(nums) {
  var answer = 0;
  let maxNum = parseInt(nums.length / 2);
  let arr = [...new Set(nums)];
  answer = Math.min(maxNum, arr.length);
  return answer;
}

console.log(solution([3, 1, 2, 3]));
