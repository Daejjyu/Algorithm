function solution(n) {
    const sqrtN = Math.sqrt(n, 2)
    return sqrtN === parseInt(sqrtN) ? Math.pow(sqrtN + 1, 2) : -1;
}