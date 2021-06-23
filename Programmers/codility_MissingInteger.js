// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
    const maxNum = 1000000
    const visited = Array(maxNum + 1).fill(0)
    for (let i = 0; i < A.length; i++) {
        if (A[i] > 0)
            visited[A[i]] = 1
    }
    for (let i = 1; i <= maxNum; i++) {
        if (visited[i] == 0)
            return i
    }
    return -1
}