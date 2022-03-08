/* get input */
const enroll = [
  "john",
  "mary",
  "edward",
  "sam",
  "emily",
  "jaimie",
  "tod",
  "young",
];
const referral = [
  "-",
  "-",
  "mary",
  "edward",
  "mary",
  "mary",
  "jaimie",
  "edward",
];
const seller = ["young", "john", "tod", "emily", "mary"];
const amount = [12, 4, 2, 5, 10];
/* get input end */

/* solve */
const solution = (enroll, referral, seller, amount) => {
  const tree = { minho: [] };
  enroll.forEach((name) => (tree[name] = []));

  referral.map((person, index) => {
    person !== "-"
      ? tree[person].push(enroll[index])
      : tree["minho"].push(enroll[index]);
  });

  const profit = seller.reduce((acc, cur, index) => {
    const cost = amount[index] * 100;
    acc[cur] ? acc[cur].push(cost) : (acc[cur] = [cost]);
    return acc;
  }, {});

  const stack = [["minho", null]];
  const visit = { minho: false };

  enroll.forEach((name) => (visit[name] = false));

  while (stack.length) {
    const [node, parent] = stack.pop();

    if (visit[node]) {
      if (profit[node] && node !== "minho") {
        for (let index = 0; index < profit[node].length; index++) {
          if (profit[node][index] === 0) continue;
          const income =
            profit[node][index] < 10 ? 0 : (profit[node][index] * 0.1) >> 0;
          profit[parent]
            ? profit[parent].push(income)
            : (profit[parent] = [income]);
          profit[node][index] -= income;
        }
      }
      continue;
    }

    stack.push([node, parent]);
    visit[node] = true;

    for (const val of tree[node]) {
      if (!visit[val]) stack.push([val, node]);
    }
  }

  return enroll.map((name) =>
    profit[name]
      ? profit[name].reduce((acc, val) => {
          return (acc = acc + val);
        })
      : 0
  );
};
/* solve end */

/* print output */
const output = solution(enroll, referral, seller, amount);
console.log(output);
/* print output end */
