function solution(A, B) {
    A.sort((a, b) => a - b)
    B.sort((a, b) => b - a)

    return A.reduce((acc, v, i) => {
        return acc + v * B[i]
    }, 0);
}