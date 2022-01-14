function isPrime(num) {
  if (!num || num === 1) return false;
  //왜 이랬을까? for(let i=2; i<+(Math.sqrt(num)/2)+1; i++){
  for (let i = 2; i <= +Math.sqrt(num); i++) {
    if (num % i === 0) return false;
  }
  return true;
}

function solution(n, k) {
  // k진법으로 나눈 후 split
  const candidates = n.toString(k).split("0");
  // 소수 개수 세기
  return candidates.filter((v) => isPrime(+v)).length;
}
