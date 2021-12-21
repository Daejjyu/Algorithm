function solution(number, k) {
  const answer = [];
  [...number].forEach(num => {
    while (k && answer.length && answer[answer.length - 1] < num) {
      answer.pop()
      k--;
    }
    answer.push(num)
  })
  if (k) answer.splice(-k)
  return answer.join('');
}