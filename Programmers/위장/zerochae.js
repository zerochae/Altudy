/* get input */
const clothes = [
  ["crowmask", "face"],
  ["bluesunglasses", "face"],
  ["smoky_makeup", "face"],
];
/* get input end */

/* solve */
const solution = (clothes) => {
  const items = new Map();

  clothes.map(([item, category]) => {
    items.has(category)
      ? items.set(category, [...items.get(category), item])
      : items.set(category, [item]);
  });

  return items.size > 1
    ? [...items.keys()].reduce((result, el) => {
        return (result *= items.get(el).length + 1);
      }, 1) - 1
    : [...items.keys()].reduce((result, el) => {
        return (result += items.get(el).length);
      }, 0);
};
/* solve end */

/* print output */
const output = solution(clothes);
console.log(output);
/* print output end */
