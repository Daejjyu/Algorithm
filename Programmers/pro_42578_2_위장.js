function solution(clothes) {
  return Object.values(clothes.reduce((a, [v, k]) => {
    a[k] = a[k] ? a[k] + 1 : 1;
    return a
  }, {})).reduce((acc, l) => acc *= l + 1, 1) - 1;
}