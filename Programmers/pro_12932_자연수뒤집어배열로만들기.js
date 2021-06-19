function solution(n) {
    return [...(n + "")].reverse().map((v) => +v);
}