// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

function solution(X, A) {
    const visited = Array(X + 1).fill(0)
    let cnt = 0
    for (let i = 0; i < A.length; i++) {
        let cur = A[i]
        if (cur <= X && visited[cur] == 0) {
            visited[cur] = 1
            cnt += 1
            if (cnt == X)
                return i
        }
    }
    return -1
}