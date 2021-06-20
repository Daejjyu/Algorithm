function solution(n) {
    return [...n.toString(3)].reverse().reduce((acc, v) => acc * 3 + 1 * v, 0);
}