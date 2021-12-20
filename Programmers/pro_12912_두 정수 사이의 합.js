function solution(a, b) {
  if (a > b) [a, b] = [b, a];
  return Array(b - a).fill(0).reduce((acc, v, i) => acc += a + i + 1, a);
}