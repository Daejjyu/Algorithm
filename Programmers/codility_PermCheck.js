// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(A) {
    const len = A.length
    const visited = Array(len + 1).fill(0)
    visited[0] = 1
    // write your code in JavaScript (Node.js 8.9.4)
    for (let i = 0; i < len; i++) {
        let cur = A[i]
        if (A[i] > len || visited[cur] === 1)
            return 0
        visited[cur] = 1
    }
    return 1
}