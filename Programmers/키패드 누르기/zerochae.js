/* get input */
const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
const hand = "right";
/* get input end */

/* set param */
const keyPad = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
  ["*", 0, "#"],
];
const lastPad = {
  left: "*",
  right: "#",
};
/* set param end */

/* solve */
const solution = (numbers, hand) => {
  return numbers.reduce((acc, num) => {
    let pad;
    const target = getPosition(num);
    const left = getPosition(lastPad.left);
    const right = getPosition(lastPad.right);
    if (target[1] === 0) {
      pad = "L";
      lastPad.left = num;
    } else if (target[1] === 2) {
      pad = "R";
      lastPad.right = num;
    } else {
      const distance_left = Math.ceil(
        Math.sqrt(
          Math.abs((target[0] - left[0]) ** 2) +
            Math.abs((target[1] - left[1]) ** 2)
        )
      );
      const distance_right = Math.ceil(
        Math.sqrt(
          Math.abs((target[0] - right[0]) ** 2) +
            Math.abs((target[1] - right[1]) ** 2)
        )
      );
      if (distance_left === distance_right) {
        if (hand === "left") {
          pad = "L";
          lastPad.left = num;
        } else {
          pad = "R";
          lastPad.right = num;
        }
      } else {
        if (distance_left < distance_right) {
          pad = "L";
          lastPad.left = num;
        } else {
          pad = "R";
          lastPad.right = num;
        }
      }
    }
    return acc + pad;
  }, "");
};

const getPosition = (num) => {
  let x = -1;
  let y = -1;
  keyPad.forEach((row, row_index) => {
    if (row.includes(num)) {
      x = row_index;
      y = row.indexOf(num);
    }
  });

  return [x, y];
};
/* solve end */

/* print output */
const output = solution(numbers, hand);
console.log(output);
/* print output end */
