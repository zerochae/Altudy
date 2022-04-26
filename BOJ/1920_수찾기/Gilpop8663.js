/* get input */
const fs = require("fs");
const filePath = fs.readFileSync("/dev/stdin");
// const filePath = `5
// 4 1 5 2 3
// 5
// 1 3 7 9 5`;

const input = filePath.toString().trim().split("\n");
/* get input end */

/* set param */

/* set param end */

/* solve */

let arr = [4, 3, 18, 1, 6, 84, 12, 65, 48, 74, 12, 36, 54];

// console.log(heapSort(arr));

function heapSort(arr) {
  for (let i = arr.length - 1; i >= 0; i--) {
    heapify(arr, i);

    if (arr[0] > arr[i]) {
      let temp = arr[i];
      arr[i] = arr[0];
      arr[0] = temp;
    }
  }

  return arr;
}

function heapify(arr, lastIdx) {
  let idx = parseInt(lastIdx / 2) - 1;

  while (idx >= 0) {
    const left = arr[idx * 2 + 1];
    const right = arr[idx * 2 + 2];

    if (left >= right && arr[idx] < left) {
      let temp = arr[idx];
      arr[idx * 2 + 1] = temp;
      arr[idx] = left;
    } else if (right > left && arr[idx] < right) {
      let temp = arr[idx];
      arr[idx * 2 + 2] = temp;
      arr[idx] = right;
    }
    idx--;
  }
  return arr;
}

const solution = (input) => {
  let set = new Set(input[1].split(" ").map((item) => item.trim()));
  const B = input[3].split(" ").map((item) => (set.has(item) ? 1 : 0));
  console.log(B.join("\n"));
};
/* solve end */

/* print output */
const output = solution(input);
// console.log(output);
/* print output end */
