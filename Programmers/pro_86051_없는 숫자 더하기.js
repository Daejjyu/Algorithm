function solution(numbers) {
  return 45 - numbers.reduce((acc, v) => acc += v, 0);
}