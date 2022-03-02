/* get input */
const numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5];
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
    const target = getPosition(num);

    if (target[1] === 0) {
      lastPad.left = num;
      return acc + "L";
    }

    if (target[1] === 2) {
      lastPad.right = num;
      return acc + "R";
    }

    const left = getPosition(lastPad.left);
    const distance_left = Math.ceil(
      Math.sqrt(
        Math.abs((target[0] - left[0]) ** 2) +
          Math.abs((target[1] - left[1]) ** 2)
      )
    );

    const right = getPosition(lastPad.right);
    const distance_right = Math.ceil(
      Math.sqrt(
        Math.abs((target[0] - right[0]) ** 2) +
          Math.abs((target[1] - right[1]) ** 2)
      )
    );

    if (distance_left === distance_right && hand === "left") {
      lastPad.left = num;
      return acc + "L";
    }

    if (distance_left === distance_right && hand === "right") {
      lastPad.right = num;
      return acc + "R";
    }

    if (distance_left < distance_right) {
      lastPad.left = num;
      return acc + "L";
    }

    if (distance_left > distance_right) {
      lastPad.right = num;
      return acc + "R";
    }

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
