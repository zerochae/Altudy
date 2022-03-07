/* get input */
const orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"];
const course = [2, 3, 4];
/* get input end */

/* solve */
const solution = (orders, course) => {
  const newMenus = new Map();
  const maxCount = {};

  course.forEach((el) => {
    maxCount[el] = 0;
  });

  course.map((course) => {
    let menus = [];

    orders.map((order) => {
      menus.push(...getCombinations(order.split(""), course));
    });

    orders.map((order) => {
      menus.map((menu) => {
        if (
          order
            .split("")
            .filter((el) => menu.includes(el))
            .sort()
            .join("") === menu.sort().join("")
        ) {
          newMenus.has(menu)
            ? newMenus.set(menu, newMenus.get(menu) + 1)
            : newMenus.set(menu, 1);
          maxCount[course] = Math.max(maxCount[course], newMenus.get(menu));
        }
      });
    });
  });

  return course.reduce((result, course) => {
    const max = maxCount[course];
    for (let key of newMenus.keys()) {
      if (
        key.length === course &&
        newMenus.get(key) === max &&
        newMenus.get(key) > 1
      ) {
        result.push(key.sort().join(""));
      }
    }

    return [...new Set(result)].sort();
  }, []);
};

const getCombinations = (arr, sel) => {
  const results = [];
  if (sel === 1) return arr.map((el) => [el]);

  arr.forEach((fixed, index, origin) => {
    results.push(
      ...getCombinations(origin.slice(index + 1), sel - 1).map((el) => [
        fixed,
        ...el,
      ])
    );
  });

  return [...new Set(results)];
};
/* solve end */

/* print output */
const output = solution(orders, course);
console.log(output);
/* print output end */
