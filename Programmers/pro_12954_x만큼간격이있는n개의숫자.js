function solution(x, n) {
    return Array(n).fill(0).map((v, i) => x * (i + 1));
}