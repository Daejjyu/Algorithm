// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
    // write your code in JavaScript (Node.js 8.9.4)
    let [sum1, sum2] = [0, 0]
    for (let i = 0; i < A.length; i++) {
        sum2 += A[i]
    }

    let answer = 2e19
    for (let i = 0; i < A.length - 1; i++) {
        sum1 += A[i]
        sum2 -= A[i]
        answer = Math.min(answer, Math.abs(sum1 - sum2))
    }
    return answer
}