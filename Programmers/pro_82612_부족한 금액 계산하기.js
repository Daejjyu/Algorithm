function solution(price, money, count) {
  const cost = parseInt(price * (1 + count) * count / 2)
  return cost > money ? cost - money : 0;
}