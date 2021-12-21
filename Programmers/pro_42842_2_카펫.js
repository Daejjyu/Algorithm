function solution(brown, yellow) {
  for (let w = 3, size = brown + yellow; w < size; w++) {
    const h = size / w
    if (h !== h | 0) continue
    if ((w - 2) * (h - 2) === yellow) return [h, w]
  }
}