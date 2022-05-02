/* get input */
const answer = [1, 2, 3, 4, 5]; // output = [1]
// const answer = [1, 3, 2, 4, 2]; // output = [1, 2, 3]
/* get input end */

/* solve */
// 라이브러리
function map(f) {
  return function* (iter) {
    for (const a of iter) yield f(a);
  };
}

function take(limit) {
  return function* (iter) {
    for (const a of iter) {
      yield a;
      if (--limit === 0) break;
    }
  };
}

function reduce(f) {
  return function (acc, iter) {
    if (!iter) acc = (iter = acc[Symbol.iterator]()).next().value;
    for (const a of iter) acc = f(acc, a);
    return acc;
  };
}

function go(arg, ...fs) {
  return reduce((arg, f) => f(arg))(arg, fs);
}

function inc(parent, k) {
  parent[k] ? parent[k]++ : (parent[k] = 1);
  return parent;
}

const countBy = (f) => (iter) =>
  reduce((counts, a) => inc(counts, f(a)))({}, iter);

const groupBy = (f) => (iter) =>
  reduce((group, a, k = f(a)) => ((group[k] = group[k] || []).push(a), group))(
    {},
    iter
  );

const isFlatable = (a) =>
  a != null && !!a[Symbol.iterator] && typeof a !== "string";

function* flat(iter) {
  for (const a of iter) isFlatable(a) ? yield* a : yield a;
}

function zip(a) {
  return function* (b) {
    a = a[Symbol.iterator]();
    b = b[Symbol.iterator]();
    while (true) {
      const { value, done } = a.next();
      const { value: value2, done: done2 } = b.next();
      if (done && done2) break;
      yield [value, value2];
    }
  };
}

// 문제 풀이
const students = [
  { name: 1, pattern: [1, 2, 3, 4, 5] },
  { name: 2, pattern: [2, 1, 2, 3, 2, 4, 2, 5] },
  { name: 3, pattern: [3, 3, 1, 1, 2, 2, 4, 4, 5, 5] },
];

const last = (arr) => arr[arr.length - 1];

// 받은 매개변수를 무한히 반복하는 함수
function* repeat(a) {
  while (true) yield a;
}

const randomAnswers = (pattern, length) =>
  go(
    pattern,
    // repeat: students 의 pattern 을 무한히 반복시킴 [[1, 2, 3, 4, 5], [1, 2, 3, 4, 5], ...]
    repeat,
    // flat: 2차원 배열을 합쳐서 1차원 배열로 만듦
    flat,
    // take: 매개변수 길이만큼만 return
    take(length)
  );

const scoring =
  (answers) =>
  ({ name, pattern }) => ({
    name,
    score: go(
      // 학생이 찍은 답안을 길이에 맞게 가져오는 함수
      randomAnswers(pattern, answers.length),
      // 정답과 찍은 값을 한쌍으로 묶어내는 함수
      zip(answers),
      // 한 쌍의 값이 같으면 'o' 다르면 'x' 로 카운팅
      countBy(([a, b]) => (a === b ? "o" : "x")),
      (counted) => counted.o || 0
    ),
  });

function solution(answers) {
  const answer = go(
    students,
    map(scoring(answers)),
    groupBy(({ score }) => score),
    Object.values,
    last,
    map(({ name }) => name),
    (_) => [..._]
  );
  return answer;
}
/* solve end */

/* print output */
const output = solution(answers);
console.log(output);
/* print output end */
