// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
    let [target, sum] = [A.length + 1, 0]
    for (let i = 0; i < A.length; i++) {
        target += (i + 1)
        sum += A[i]
    }
    return target - sum
}