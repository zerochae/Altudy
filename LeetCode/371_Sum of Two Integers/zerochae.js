const input = {
  a: 1,
  b: 2,
};

/**
 * Given two integers a and b,
 * return the sum of the two integers without using the operators + and -.
 * @param {number} a
 * @param {number} b
 * @return {number}
 */

const getSum = (a, b) => {
  const B = (a & b) << 1;
  const A = a ^ b;

  if (B === 0) return A;
  else if (A === 0) return B;
  return getSum(A, B);
};

const output = getSum(input.a, input.b);

console.log(output);
