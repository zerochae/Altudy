const mat = [
  [1, 1, 0, 0, 0],
  [1, 1, 1, 1, 0],
  [1, 0, 0, 0, 0],
  [1, 1, 0, 0, 0],
  [1, 1, 1, 1, 1],
];
const k = 3;

const kWeakestRows = (mat, k) => {
  return mat
    .map((row, index) => [row, index])
    .sort((a, b) => a[0].filter(Boolean).length - b[0].filter(Boolean).length)
    .slice(0, k)
    .map(([_, index]) => index);
};

const output = kWeakestRows(mat, k);

console.log(output);
