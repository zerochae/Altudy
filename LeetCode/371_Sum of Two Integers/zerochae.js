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
  const A = a ^ b;
  const B = (a & b) << 1;

  return A === 0 ? B : B === 0 ? A : getSum(A, B);
};

const output = getSum(input.a, input.b);

console.log(output);
