function solution(n) {
    return [...n + ''].reduce((acc, v) => acc += +v, 0);
}