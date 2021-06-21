function solution(land) {
    const len = land.length
    for (let i = 1; i < len; i++) {
        for (let j = 0; j < 4; j++) {
            land[i][j] += Math.max(land[i - 1][(j + 1) % 4], land[i - 1][(j + 2) % 4], land[i - 1][(j + 3) % 4])
        }
    }
    return Math.max(...land[len - 1]);
}