function getFirstHalf(str) {
  return str.slice(0, Math.floor(str.length / 2));
}

function getLastHalf(str) {
  return str.slice(Math.floor(str.length / 2), str.length);
}

function multiplyTwoIntegers(num1, num2) {
  const str1 = num1.toString();
  const str2 = num2.toString();

  const a = BigInt(getFirstHalf(str1));
  const b = BigInt(getLastHalf(str1));
  const c = BigInt(getFirstHalf(str2));
  const d = BigInt(getLastHalf(str2));

  let ac;
  if (a < 10 && c < 10) {
    ac = a * c;
  } else {
    ac = multiplyTwoIntegers(a, c);
  }

  let ad;
  if (a < 10 && d < 10) {
    ad = a * d;
  } else {
    ad = multiplyTwoIntegers(a, d);
  }

  let bc;
  if (b < 10 && c < 10) {
    bc = b * c;
  } else {
    bc = multiplyTwoIntegers(b, c);
  }

  let bd;
  if (b < 10 && d < 10) {
    bd = b * d;
  } else {
    bd = multiplyTwoIntegers(b, d);
  }

  const n = Math.max(str1.length, str2.length);
  const tenPowN = BigInt(10) ** BigInt(n); // Don't use Math.pow here!
  const tenPowN2 = BigInt(10) ** BigInt(n / 2); // remember that JS is kind of weird, so BigInt(a) * BigInt(b) !== BigInt(a * b)

  return tenPowN * ac + tenPowN2 * (ad + bc) + bd;
}

const int1 = BigInt(
  "3141592653589793238462643383279502884197169399375105820974944592"
);
const int2 = BigInt(
  "2718281828459045235360287471352662497757247093699959574966967627"
);

// algorithm result using recursion
const result = multiplyTwoIntegers(int1, int2);
console.log("result", result);

// answer using JS native multiplication of BigInts.
const answer = int1 * int2;
console.log("answer", answer);

console.log("correct", result === answer);
