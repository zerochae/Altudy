function isPrime(num) {
  if (num === 1) return false;
  let prime = false;
  let ch = Array.from({ length: num + 1 }, () => 0);
  for (let i = 2; i <= num; i++) {
    if (ch[i] === 0) {
      for (let j = 2 * i; j <= num; j += i) {
        ch[j] = 1;
      }
    }
  }
  if (ch[num] === 0) prime = true;
  return prime;
}

function solution(nums) {
  var answer = 0;
  function DFS(L, s, sum) {
    if (L === 3) {
      isPrime(sum) ? answer++ : answer;
    } else {
      for (let i = s; i < nums.length; i++) {
        DFS(L + 1, i + 1, sum + nums[i]);
      }
    }
  }
  DFS(0, 0, 0);
  return answer;
}

console.log(solution([1, 2, 7, 6, 4]));
