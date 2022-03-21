const info = [
  "java backend junior pizza 150",
  "python frontend senior chicken 210",
  "python frontend senior chicken 150",
  "cpp backend senior pizza 260",
  "java backend junior chicken 80",
  "python backend senior chicken 50",
];

const query = [
  "java and backend and junior and pizza 100",
  "python and frontend and senior and chicken 200",
  "cpp and - and senior and pizza 250",
  "- and backend and senior and - 150",
  "- and - and - and chicken 100",
  "- and - and - and - 150",
];

const solution = (info, query) => {
  const map = setInfo(info);

  return query.reduce((result, row) => {
    const q = row.split(" ").filter((el) => el !== "and" && el !== "-");
    const score = parseInt(q.pop());

    result.push(
      Array.from(map.keys())
        .filter((key) => q.every((val) => key.includes(val)))
        .reduce((acc, key) => acc + search(map.get(key), score), 0)
    );
    return result;
  }, []);
};

const setInfo = (info) => {
  const map = new Map();

  info.map((row) => {
    const i = row.split(" ");
    const score = Number(i.pop());
    const key = i.join(" ");
    !map.has(key) ? map.set(key, [score]) : map.get(key).push(score);
  });

  for (const key of map.keys()) {
    map.get(key).sort((a, b) => a - b);
  }

  return map;
};

const search = (arr, target) => {
  if (arr) {
    let start = 0;
    let end = arr.length;
    while (start < end) {
      const mid = Math.floor((start + end) / 2);
      if (target <= arr[mid]) end = mid;
      else if (target > arr[mid]) start = mid + 1;
    }
    return arr.length - start;
  }
  return 0;
};

const output = solution(info, query);
console.log(output);
