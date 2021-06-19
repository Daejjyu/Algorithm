function solution(x) {
    const sum = [...x + ""].reduce((acc, v) => acc + 1 * v, 0)
    return x % sum === 0;
}