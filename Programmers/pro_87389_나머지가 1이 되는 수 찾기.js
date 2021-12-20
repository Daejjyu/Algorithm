function solution(n) {
  let answer = n - 1;
  for (let i = 0, sqrt = Math.sqrt(n - 1); i <= sqrt; i++) {
    if (n % i == 1) return i
  }
  return answer;
}