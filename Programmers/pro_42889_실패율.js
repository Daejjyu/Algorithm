function solution(N, stages) {
    const arrived = Array(N + 1).fill(0)
    const visited = Array(N + 1).fill(0)
    stages.forEach((v) => arrived[N - (v - 1)] += 1)
    arrived.reduce((acc, v, i) => {
        visited[N - i] = acc
        return acc + v
    }, 0)
    visited.unshift(stages.length)
    return [...new Array(N)].map((v, i) => i + 1)
        .sort((a, b) => arrived[N - (a - 1)] / visited[a - 1] > arrived[N - (b - 1)] / visited[b - 1] ? -1 : 1);
}