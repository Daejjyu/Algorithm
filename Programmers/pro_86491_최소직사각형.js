afunction solution(sizes) {
  let [maxW, maxH] = [0, 0];
  sizes.forEach(([a, b]) => {
    if (a > b) [a, b] = [b, a]
    maxW = Math.max(a, maxW)
    maxH = Math.max(b, maxH)
  })
  return maxW * maxH;
}