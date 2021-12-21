function solution(num) {
  let iter = 0;
  while (iter < 500) {
    if (num === 1) return iter
    if (num % 2) num = num * 3 + 1
    else num /= 2
    iter++;
  }
  return -1;
}