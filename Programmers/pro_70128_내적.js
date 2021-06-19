function solution(a, b) {
    return a.reduce((acc, v, i) => acc + v * b[i], 0);
}