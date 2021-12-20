function solution(x) {
    const digitSum = [...x + ''].reduce((a, v) => a += v | 0, 0)
    return x % digitSum === 0;
}