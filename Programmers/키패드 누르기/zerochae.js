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

    const left = getDistance(target, getPosition(lastPad.left));
    const right = getDistance(target, getPosition(lastPad.right));

    if (left === right && hand === "left") {
      lastPad.left = num;
      return acc + "L";
    }

    if (left === right && hand === "right") {
      lastPad.right = num;
      return acc + "R";
    }

    if (left < right) {
      lastPad.left = num;
      return acc + "L";
    }

    if (left > right) {
      lastPad.right = num;
      return acc + "R";
    }
  }, "");
};

const getPosition = (num) => {
  
  return keyPad.reduce((position, row, index) => {
    if (row.includes(num)) {
      position = [index, row.indexOf(num)];
    }
    return position;
  }, []);
};

const getDistance = (a, b) => {
  
  return Math.ceil(
    Math.sqrt(Math.abs((a[0] - b[0]) ** 2) + Math.abs((a[1] - b[1]) ** 2))
  );
};
/* solve end */

/* print output */
const output = solution(numbers, hand);
console.log(output);
/* print output end */
