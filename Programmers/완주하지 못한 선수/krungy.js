/* get input */
const participant = ["leo", "kiki", "eden"];
const completion = ["eden", "kiki"]; // output = "leo"

// const participant = ["marina", "josipa", "nikola", "vinko", "filipa"];
// const completion = ["josipa", "filipa", "marina", "nikola"]; // output = "vinko"

// const participant = ["mislav", "stanko", "mislav", "ana"];
// const completion = ["stanko", "ana", "mislav"]; // output = "mislav"
/* get input end */

/* solve */
const find = (f) => (iter) => head(filter(f)(iter));

function go(arg, ...fs) {
  return reduce((arg, f) => f(arg))(arg, fs);
}

function* entries(obj) {
  for (const k in obj) yield [k, obj[k]];
}

function filter(f, iter) {
  return function* (iter) {
    for (const a of iter) if (f(a)) yield a;
  };
}

const head = ([a]) => a;

const curry =
  (f) =>
  (a, ..._) =>
    _.length ? f(a, ..._) : (..._) => f(a, ..._);

const reduce = curry((f, acc, iter) => {
  if (!iter) {
    iter = acc[Symbol.iterator]();
    acc = iter.next().value;
  }
  for (const a of iter) {
    acc = f(acc, a);
  }
  return acc;
});

function inc(parent, k) {
  parent[k] ? parent[k]++ : (parent[k] = 1);
  return parent;
}

// 참가자와 완주자의 이름별 개수 세기
const count = (args) => {
  let obj = {};
  for (const a of args) inc(obj, a);
  return obj;
};

// 완주하지 못한 사람의 이름 찾기
const findFail = (participant, completion) =>
  go(
    participant,
    entries,
    find(([name, count]) => (completion[name] || 0) < count),
    head
  );

// 결과 확인
function solution(participant, completion) {
  const answer = findFail(count(participant), count(completion));
  return answer;
}
/* solve end */

/* print output */
const output = solution(numbers);
console.log(output);
/* print output end */
